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
*    Singleton
*/
+ (instancetype)shared;


/**
 *    Get device list
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryDevices:(nullable void (^)(NSArray<ALFDeviceInfoModel *> *))success
             failure:(nullable void (^)(ALFError *))failure;


/**
 *    Get details of a  device
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryDeviceInfo:(NSString *)deviceId
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;


/**
 *    Online status
 *
 */
-(ALFDeviceOnlineStatus)onlineStatusWithDeviceId:(NSString *)deviceId;



/**
 *  Establish a P2P connection to the device (to revert the status, please register ALFDeviceDelegate).
 *  @param     deviceId              deviceId
 */
-(void)connectedWithDeviceId:(NSString *)deviceId;


/**
 *    Forced reconnection equipment
 *    @param     deviceId              deviceId
 */
-(void)forceReConectedWithCameraID:(NSString *)deviceId;


/**
 *    Reset all P2P connections
 *
 */
-(void)resetConnection;


- (void)connectionShouldEncrypt:(BOOL)ShouldEncrypt DeviceId:(NSString *)deviceId;


/**
 *    Please call if the network environment changes.
 *
 */
-(void)networkChangeAction;

/**
 *    Query device connection status
 *
 */
-(ALFDeviceConnectStatus)statusForCamera:(NSString *)deviceId;

/**
 *    Disconnect device
 *    @param     deviceId              deviceId
 */
-(void)disConnectedWithCamID:(NSString *)deviceId;


/**
 *    PTZControl Single-Step Mobile Gimbal
 *    @param     deviceId              deviceId
 */
- (void)cameraPtzControl:(NSString *)deviceId direction:(ALFDevicePTZControlDirection)direct;

/**
 *    PTZControl Continuous Movement Start
 *    @param     deviceId              deviceId
 */
- (void)cameraPtzContinueControl:(NSString *)deviceId direction:(ALFDevicePTZControlDirection)direct;

/**
 *    PTZControl continuous movement ends
 *    @param     deviceId              deviceId
 */
- (void)cameraPtzControlEnd:(NSString *)deviceId;

/**
 *    PTZControl reset
 *    @param     deviceId              deviceId
 */
- (void)cameraPtzResetControl:(NSString *)deviceId;


/**
 *    Get video resolution
 *    @param     deviceId              deviceId
 */

- (NSArray *)getResolutions:(NSString *)deviceId;

- (NSString *)getDefaultResolution:(NSString *)deviceId;

/**
 *    Change video resolution
 *    @param     deviceId              deviceId
 *    @param     resoNum              Resolution
 */
- (void)changeResolution:(NSString *)deviceId quilt:(NSString *)resoNum;



/**
 *    Initialize remote TF card
 *    @param     deviceId              deviceId
 */
- (void)initRemoteTF:(NSString *)deviceId
             success:(nullable void (^)(NSString *))success
             failure:(nullable void (^)(ALFError *))failure;

/**
 *    Force disconnect device
 *    @param     deviceId              deviceId
 */
- (void)forceDisconenct:(NSString *)deviceId;


/**
 *    Get cloud storage calendar list
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryCloudStorageCalendarMasterUid:(NSString*)masterUid
                                  deviceId:(NSString *)deviceId
                                   success:(nullable void (^)(NSArray<NSString *> *))success
                                   failure:(nullable void (^)(ALFError *))failure;

/**
 *    Get cloud storage list
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryCloudStorageVideoListMasterUid:(NSString*)masterUid
                                   deviceId:(NSString *)deviceId
                                 dayStartTs:(double)dayStartTs
                                   dayEndTs:(double)dayEndTs
                                    success:(nullable void (^)(NSArray<ALFCloudStorageModel *> *))success
                                    failure:(nullable void (^)(ALFError *))failure;


/**
 *    Get TFCard calendar list
 *     This is only effective after remoteTFCardInit succeeds.
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryTFCardCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(ALFError *))failure
                       refreshBlock:(void (^)(void))refreshBlock;


/**
 *    Get TFCard video list
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryTFCardVideoListDeviceId:(NSString *)deviceId
                          dayStartTs:(double)dayStartTs
                            dayEndTs:(double)dayEndTs
                             success:(nullable void (^)(NSArray<ALFCloudStorageModel *> *))success
                             failure:(nullable void (^)(ALFError *))failure
                        refreshBlock:(void (^)(void))refreshBlock;



/**
 *    Get Alarm Calendar List
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryAlarmCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(ALFError *))failure;

/**
 *    Get Alarm List
 *
 *     @param     cdate                date
 *     @param     limit                limit（ -1: All）
 *     @param     isToday               Is it today  (0 or 1)
 *     @param     isTodayFirst          Is this the first request of the day  (0 or 1)
 *     @param     ctime          End of current date, e.g., 2022116235959
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
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
 *    Delete cloud storage videos
 *  Cloud storage time format: 20221116235959000, accurate to milliseconds.
 *     @param     start                start
 *     @param     end                    end
 *     @param     relDays               The beginning and end of deleting all day
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 *
 */
- (void)deleteCloudVideoList:(NSString * _Nonnull)deviceId
                       start:(ALFCloudStorageDeleteModel * _Nonnull)start
                         end:(ALFCloudStorageDeleteModel * _Nonnull)end
                     relDays:(ALFCloudStorageDeleteRealDayModel * _Nonnull)relDays
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(ALFError *))failure;



/**
 *    Get view angles
 *
 */
- (NSArray<ALFViewAngleModel *> *)getViewAngles:(NSString *)deviceId;


/**
 *    Add view angle
 *     @param     angleIndex           view angle id
 *     @param     image                Preview image
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 *
 */
- (void)viewAngleAdd:(NSString *)deviceId
          angleIndex:(NSString *)angleIndex
        previewImage:(UIImage *)image
             success:(void (^)(void))success
             failure:(void (^)(ALFError * _Nonnull))failure;

/**
 *    Delete view angle
 *     @param     angleIndex           view angle id
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 *
 */
- (void)deleViewAngle:(NSString *)deviceId
           angleIndex:(NSString *)angleIndex
              success:(void (^)(void))success
              failure:(void (^)(ALFError * _Nonnull))failure;


/**
 *    Turn to the  view angle
 *     @param     angleIndex           view angle id
 *
 */
- (void)moveToViewAngle:(NSString *)deviceId
             angleIndex:(NSString *)angleIndex;


/**
 *    Is the alarm turned on
 *
 */
- (BOOL)sirenIsOn:(NSString *)deviceId;


/**
 *    Is humanoid tracking enabled
 *
 */
- (BOOL)triggerByMotionIsOn:(NSString *)deviceId;


/**
 *    Is the white light on
 *
 */
- (BOOL)lightIsOn:(NSString *)deviceId;


/**
 *    Delete alerts
 *     @param     cdate           date
 *     @param     ctss           The CTS array that needs to have its alarms deleted.
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 *
 */
- (void)deleteAlarms:(NSString *)deviceId
              cdate:(NSString *)cdate
               ctss:(NSArray *)ctss
            success:(void (^)(void))success
            failure:(void (^)(ALFError * _Nonnull))failure;


/**
 *    Get preview image
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 *
 */
- (void)getSnapshot:(NSString *)deviceId
                url:(NSString *)url
            success:(void (^)(UIImage * _Nonnull))success
            failure:(void (^)(ALFError * _Nonnull))failure;

/**
 *    Device group
 */
- (ALFDeviceGroup)getDeviceGroup:(NSString *)deviceId;

/**
 *    Is it a blacklisted device
 */
- (BOOL)isBlacklist:(NSString *)deviceId;


/**
 *    Is it a blacklisted device
 */
- (BOOL)needBindCloudStorage:(NSString *)deviceId;



/**
 *    ISP locking
 */
- (BOOL)isISPLocking:(NSString *)deviceId;

@end


NS_ASSUME_NONNULL_END
