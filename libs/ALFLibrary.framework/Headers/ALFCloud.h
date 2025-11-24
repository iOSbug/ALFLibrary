//
//  ALFCloud.h
//  ALFLibrary
//
//  Created by iOS on 2023/11/20.
//

#import <Foundation/Foundation.h>
#import "ALFCloudOrderModel.h"
#import "ALFError.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFCloud : NSObject
/**
*    Singleton
*/
+ (instancetype)shared;


/**
 *    Get cloud storage package list
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)queryCloudOrderList:(nullable void (^)(NSArray<ALFCloudOrderModel *> *))success
                    failure:(nullable void (^)(ALFError *))failure;



/**
 *    Binding cloud storage package
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)joinCloudOrder:(NSString *)deviceId
               orderId:(NSString *)orderId
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



/**
 *    Replace cloud storage plan
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)replacCloudOrder:(NSString *)deviceId
          replceDeviceId:(NSString *)replceDeviceId
                 orderId:(NSString *)orderId
         appCloudStorUrl:(NSString *)appCloudStorUrl
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;


@end

NS_ASSUME_NONNULL_END
