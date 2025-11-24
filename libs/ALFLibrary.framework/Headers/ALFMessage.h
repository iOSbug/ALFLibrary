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
*    Singleton
*/
+ (instancetype)shared;

/**
 *    Initialize push
 */
- (void)initPush;

/**
 *    Initialize push parameters and retrieve the Firebase device token via callback.
 */
- (void)initPush:(nullable void (^)(NSString *))deviceToken;

/**
 *    Set Firebase pushtoken
 */
- (void)setFirebasePushToken:(NSString *)deviceToken;

/**
 *    Processing push messages
 *    @param     notiResponse               推送消息
 */
- (void)handleApnsNotiReponse:(UNNotificationResponse *)notiResponse;

/**
 *    Get an overview of device alarm messages
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryAlertsSurvey:(nullable void (^)(NSArray<ALFAlertSurveyModel *> *))success
                  failure:(nullable void (^)(ALFError *))failure;


/// Get the blue calendar dot containing alarm videos.
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)fetchAlertsCalendar:(NSString *)deviceId
                    success:(nullable void (^)(ALFAlertsCalendarModel *))success
                    failure:(nullable void (^)(ALFError *))failure;



/// Get Alarm List
/// @param deviceId deviceId
/// @param cdate The date in the camera's time zone,  20180710
/// @param success success
/// @param failure failure
- (void)getAlertsList:(NSString *)deviceId
                cdate:(NSString *)cdate
              success:(nullable void (^)(ALFAlertsListModel *))success
              failure:(nullable void (^)(ALFError *))failure;


/// Delete alerts
/// @param deviceId deviceId
/// @param cdate The date in the camera's time zone,  20180710
/// @param ctss Batch delete
/// @param success success
/// @param failure failure
- (void)deleteAlert:(NSString *)deviceId
              cdate:(NSString *)cdate
               ctss:(NSArray<NSString *> *)ctss
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;



@end

NS_ASSUME_NONNULL_END
