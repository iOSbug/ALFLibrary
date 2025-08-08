//
//  ALFMessage.h
//  ALFLibrary
//
//  Created by Tianbao Wang on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "ALFError.h"
#import "ALFAlertSurveyModel.h"
#import "ALFAlertsCalendarModel.h"
#import "ALFAlertsListModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    PushSettingTypeUpsert,
    PushSettingTypeRemove
} PushSettingType;

@interface ALFMessage : NSObject

/**
*    单例
*/
+ (instancetype)shared;

/**
 *    初始化推送参数
 */
- (void)initPush;

/**
 *    初始化推送参数，回调获取到的firebase的deivcetoken
 */
- (void)initPush:(nullable void (^)(NSString *))deviceToken;

/**
 *    设置firebase的pushtoken
 */
- (void)setFirebasePushToken:(NSString *)deviceToken;

/**
 *    处理推送消息
 *    @param     notiResponse               推送消息
 */
- (void)handleApnsNotiReponse:(UNNotificationResponse *)notiResponse;

/**
 *    获取设备告警消息概览
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryAlertsSurvey:(nullable void (^)(NSArray<ALFAlertSurveyModel *> *))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 获取含有告警视频的日历小蓝点
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)fetchAlertsCalendar:(NSString *)deviceId
                    success:(nullable void (^)(ALFAlertsCalendarModel *))success
                    failure:(nullable void (^)(ALFError *))failure;



/// 获取告警列表
/// @param deviceId 设备ID
/// @param cdate 摄像头时区的日期，20180710
/// @param success success
/// @param failure failure
- (void)getAlertsList:(NSString *)deviceId
                cdate:(NSString *)cdate
              success:(nullable void (^)(ALFAlertsListModel *))success
              failure:(nullable void (^)(ALFError *))failure;


/// 删除告警
/// @param deviceId 设备ID
/// @param cdate 摄像头时区的日期，20180710
/// @param ctss 批量删除
/// @param success success
/// @param failure failure
- (void)deleteAlert:(NSString *)deviceId
              cdate:(NSString *)cdate
               ctss:(NSArray<NSString *> *)ctss
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;



@end

NS_ASSUME_NONNULL_END
