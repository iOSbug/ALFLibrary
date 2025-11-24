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
*    Singleton
*/
+ (instancetype)shared;


/**
 *    Get the bind token
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
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


/// QR code network configuration
/// @param token  bind Token
/// @param timeout  timeout(s)
/// @param success Successful callback
/// @param failure failure
- (void)startQRWiFiConfig:(NSString *)token
                  timeout:(NSTimeInterval)timeout
                  success:(nullable void (^)(ALFBindDeviceModel *))success
                  failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
