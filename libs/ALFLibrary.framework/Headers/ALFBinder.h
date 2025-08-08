//
//  ALFBinder.h
//  ALFLibrary
//
//  Created by Tianbao Wang on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import "ALFError.h"
#import "ALFWifiListModel.h"
#import "ALFDiscoverDeviceModel.h"
#import "ALFDeviceInfoModel.h"
#import "ALFBindDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ALFBinderModeQR,
    ALFBinderModeSoftAP,
    ALFBinderModeEth,
    ALFBinderModeOnlineSetWiFi,
} ALFBinderMode;


@interface ALFBinder : NSObject

/**
*    单例
*/
+ (instancetype)shared;


/**
 *    获取配网token
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)getToken:(nullable void (^)(NSString *))success
         failure:(nullable void (^)(ALFError *))failure;


/// Create QR code string
/// @param ssid Name of route
/// @param password Password of route
/// @param token Bind Token
/// @param success success
/// @param failure failure
- (void)createQRString:(NSString *)ssid
              password:(NSString *)password
             bindToken:(NSString *)token
               success:(nullable void (^)(NSString *))success
               failure:(nullable void (^)(ALFError *))failure;


/// 二维码配网
/// @param token 配网token，从getToken获取
/// @param timeout 配网超时时长 (秒)
/// @param success 回调当前绑定的设备 ID
/// @param failure failure
- (void)startQRWiFiConfig:(NSString *)token
                  timeout:(NSTimeInterval)timeout
                  success:(nullable void (^)(ALFBindDeviceModel *))success
                  failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
