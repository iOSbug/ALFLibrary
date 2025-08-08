//
//  ALFBanner.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/14.
//

#import <Foundation/Foundation.h>
#import "ALFBannerModel.h"
#import "ALFError.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFBanner : NSObject
/**
*    单例
*/
+ (instancetype)shared;


/**
 *    获取列表 banner 通知
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)fetchBanner:(nullable void (^)(ALFBannerModel *))success
            failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
