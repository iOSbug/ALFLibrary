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
*    单例
*/
+ (instancetype)shared;


/**
 *    获取云存套餐列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudOrderList:(nullable void (^)(NSArray<ALFCloudOrderModel *> *))success
                    failure:(nullable void (^)(ALFError *))failure;



/**
 *    绑定云存套餐
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)joinCloudOrder:(NSString *)deviceId
               orderId:(NSString *)orderId
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



/**
 *    替换云存套餐
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)replacCloudOrder:(NSString *)deviceId
          replceDeviceId:(NSString *)replceDeviceId
                 orderId:(NSString *)orderId
         appCloudStorUrl:(NSString *)appCloudStorUrl
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;


@end

NS_ASSUME_NONNULL_END
