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
*    Singleton
*/
+ (instancetype)shared;


/**
 *    Get banner 
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)fetchBanner:(nullable void (^)(ALFBannerModel *))success
            failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
