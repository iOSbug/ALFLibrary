//
//  ALFDevice.h
//  ALFLibrary
//
//  Created by Tianbao Wang on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ALFError.h"
#import "ALFDeviceInfoModel.h"
#import "ALFCloudStorageModel.h"
#import "ALFAlarmListModel.h"
#import "ALFCloudStorageDeleteModel.h"
#import "ALFQualityModel.h"
#import "ALFDefine.h"
#import "ALFViewAngleModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^tfSuccess)(NSString* portNum);

typedef void(^tfFailure)(ALFError *error);

typedef enum {
    ALFDeviceConnectStatusConnecting=1,
    ALFDeviceConnectStatusConnected,
    ALFDeviceConnectStatusDisConnected,
    ALFDeviceConnectStatusFailed,
    ALFDeviceConnectStatusOffline
}ALFDeviceConnectStatus;


typedef enum {
    ALFDeviceStatusOffline = 1,     //offline
    ALFDeviceStatusOnline = 2,      //online
    ALFDeviceStatusUpgrading = 4,   //upgrading
    ALFDeviceStatusHibernate = 8,   //hibernate
}ALFDeviceOnlineStatus;


typedef enum : NSUInteger {
    ALFDevicePTZControlDirectionUp,
    ALFDevicePTZControlDirectionLeft,
    ALFDevicePTZControlDirectionDown,
    ALFDevicePTZControlDirectionnRight,
    ALFDevicePTZControlDirectionCenter,
} ALFDevicePTZControlDirection;

@protocol ALFDeviceDelegate <NSObject>
@optional
/**
 *  设备连接P2P状态回调
 *  @param     deviceId              摄像头id
 *  @param     status                连接状态
 */
- (void)connectStatusWithDeviceId:(NSString *)deviceId status:(ALFDeviceConnectStatus)status;

@end





@interface ALFDevice : NSObject
@property (weak)                        id<ALFDeviceDelegate>   delegate;
/**
*    单例
*/
+ (instancetype)shared;


/**
 *    获取设备列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryDevices:(nullable void (^)(NSArray<ALFDeviceInfoModel *> *))success
             failure:(nullable void (^)(ALFError *))failure;


/**
 *    获取单个设备详情
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryDeviceInfo:(NSString *)deviceId
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;


/**
 *    在线状态
 *
 */
-(ALFDeviceOnlineStatus)onlineStatusWithDeviceId:(NSString *)deviceId;



/**
 *  对设备进行P2P连线（状态回掉请注册ALFDeviceDelegate）
 *  @param     deviceId              摄像头id
 */
-(void)connectedWithDeviceId:(NSString *)deviceId;


/**
 *    强制重联设备
 *    @param     deviceId              摄像头id
 */
-(void)forceReConectedWithCameraID:(NSString *)deviceId;


/**
 *    重置所有P2P连接
 *
 */
-(void)resetConnection;


- (void)connectionShouldEncrypt:(BOOL)ShouldEncrypt DeviceId:(NSString *)deviceId;


/**
 *    网络环境发生变化请调用
 *
 */
-(void)networkChangeAction;
/**
 *    查询设备连接状态
 *
 */
-(ALFDeviceConnectStatus)statusForCamera:(NSString *)deviceId;

/**
 *    断开设备连接
 *    @param     deviceId              摄像头id
 */
-(void)disConnectedWithCamID:(NSString *)deviceId;


/**
 *    PTZControl单步移动云台
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzControl:(NSString *)deviceId direction:(ALFDevicePTZControlDirection)direct;

/**
 *    PTZControl连续移动开始
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzContinueControl:(NSString *)deviceId direction:(ALFDevicePTZControlDirection)direct;

/**
 *    PTZControl连续移动结束
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzControlEnd:(NSString *)deviceId;

/**
 *    PTZControl回正
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzResetControl:(NSString *)deviceId;


/**
 *    获取视频分辨率
 *    @param     deviceId              摄像头id
 */

- (NSArray *)getResolutions:(NSString *)deviceId;

- (NSString *)getDefaultResolution:(NSString *)deviceId;

/**
 *    改变视频分辨率
 *    @param     deviceId              摄像头id
 *    @param     resoNum              分辨率参数
 */
- (void)changeResolution:(NSString *)deviceId quilt:(NSString *)resoNum;



/**
 *    初始化远程TF卡
 *    @param     deviceId              摄像头id
 *    YES :成功
 *    NO: 失败
 */
- (void)initRemoteTF:(NSString *)deviceId
             success:(nullable void (^)(NSString *))success
             failure:(nullable void (^)(ALFError *))failure;

/**
 *    强制断开设备
 *    @param     deviceId              摄像头id
 */
- (void)forceDisconenct:(NSString *)deviceId;


/**
 *    获取云存储日历列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudStorageCalendarMasterUid:(NSString*)masterUid
                                  deviceId:(NSString *)deviceId
                                   success:(nullable void (^)(NSArray<NSString *> *))success
                                   failure:(nullable void (^)(ALFError *))failure;

/**
 *    获取云存储列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudStorageVideoListMasterUid:(NSString*)masterUid
                                   deviceId:(NSString *)deviceId
                                 dayStartTs:(double)dayStartTs
                                   dayEndTs:(double)dayEndTs
                                    success:(nullable void (^)(NSArray<ALFCloudStorageModel *> *))success
                                    failure:(nullable void (^)(ALFError *))failure;


/**
 *    获取TFCard日历列表
 *     !!!!只有当remoteTFCardInit 成功后才有效
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryTFCardCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(ALFError *))failure
                       refreshBlock:(void (^)(void))refreshBlock;


/**
 *    获取TFCard视频列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryTFCardVideoListDeviceId:(NSString *)deviceId
                          dayStartTs:(double)dayStartTs
                            dayEndTs:(double)dayEndTs
                             success:(nullable void (^)(NSArray<ALFCloudStorageModel *> *))success
                             failure:(nullable void (^)(ALFError *))failure
                        refreshBlock:(void (^)(void))refreshBlock;



/**
 *    获取告警日历列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryAlarmCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(ALFError *))failure;

/**
 *    获取告警列表
 *
 *     @param     cdate                日期
 *     @param     limit                获取数量 -1:全部
 *     @param     isToday               是否为今天   0 or 1
 *     @param     isTodayFirst          是否今天第一次请求 0 or 1
 *     @param     ctime          当前日期的结束 eg:2022116235959
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
-(void)queryAlarmListWithDeviceId:(NSString *)deviceId
                            cdate:(NSString * _Nonnull)cdate
                            limit:(NSInteger)limit
                          isToday:(NSInteger)isToday
                     isTodayFirst:(NSInteger)isTodayFirst
                            ctime:(NSInteger)ctime
                          success:(nullable void (^)(ALFAlarmListModel *))success
                          failure:(nullable void (^)(ALFError *))failure;

/**
 *    删除云存储视频
 *云存储时间格式：20221116235959000 精度到毫秒
 *     @param     start                开始
 *     @param     end                结束
 *     @param     relDays               整天删除的开始和结束
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleteCloudVideoList:(NSString * _Nonnull)deviceId
                       start:(ALFCloudStorageDeleteModel * _Nonnull)start
                         end:(ALFCloudStorageDeleteModel * _Nonnull)end
                     relDays:(ALFCloudStorageDeleteRealDayModel * _Nonnull)relDays
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(ALFError *))failure;



/**
 *    获取视角
 *
 */

- (NSArray<ALFViewAngleModel *> *)getViewAngles:(NSString *)deviceId;


/**
 *    添加视角
 *     @param     angleIndex           需要添加的视角的索引
 *     @param     image                预览图
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */

- (void)viewAngleAdd:(NSString *)deviceId
          angleIndex:(NSString *)angleIndex
        previewImage:(UIImage *)image
             success:(void (^)(void))success
             failure:(void (^)(ALFError * _Nonnull))failure;

/**
 *    删除视角
 *     @param     angleIndex           需要删除的视角的索引
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleViewAngle:(NSString *)deviceId
           angleIndex:(NSString *)angleIndex
              success:(void (^)(void))success
              failure:(void (^)(ALFError * _Nonnull))failure;


/**
 *    转向指定视角
 *     @param     angleIndex           需要转向的视角的索引
 *
 */
- (void)moveToViewAngle:(NSString *)deviceId
             angleIndex:(NSString *)angleIndex;


/**
 *    报警是否打开
 *
 */
- (BOOL)sirenIsOn:(NSString *)deviceId;


/**
 *    人形跟追是否打开
 *
 */
- (BOOL)triggerByMotionIsOn:(NSString *)deviceId;


/**
 *    白光灯是否打开
 *
 */
- (BOOL)lightIsOn:(NSString *)deviceId;


/**
 *    删除告警
 *     @param     cdate           日期
 *     @param     ctss           需要删除告警的cts 数组
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleteAlarms:(NSString *)deviceId
              cdate:(NSString *)cdate
               ctss:(NSArray *)ctss
            success:(void (^)(void))success
            failure:(void (^)(ALFError * _Nonnull))failure;


/**
 *    获取预览图
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)getSnapshot:(NSString *)deviceId
                url:(NSString *)url
            success:(void (^)(UIImage * _Nonnull))success
            failure:(void (^)(ALFError * _Nonnull))failure;

/**
 *    设备类型
 */
- (ALFDeviceGroup)getDeviceGroup:(NSString *)deviceId;

/**
 *    是否是黑名单设备
 */
- (BOOL)isBlacklist:(NSString *)deviceId;


/**
 *    是否是黑名单设备
 */
- (BOOL)needBindCloudStorage:(NSString *)deviceId;



/**
 *    是否锁定
 */
- (BOOL)isISPLocking:(NSString *)deviceId;

@end


NS_ASSUME_NONNULL_END
