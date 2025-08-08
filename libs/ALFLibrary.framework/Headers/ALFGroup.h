//
//  ALFGroup.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/14.
//

#import <Foundation/Foundation.h>
#import "ALFGroupsModel.h"
#import "ALFError.h"
#import "ALFDeviceInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFGroup : NSObject

/**
*    单例
*/
+ (instancetype)shared;


/**
 *    政企分组列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)fetchGroupList:(nullable void (^)(ALFGroupsModel *))success
               failure:(nullable void (^)(ALFError *))failure;


/**
 *    政企分组添加
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupAdd:(NSString *)groupName
         success:(nullable void (^)(ALFGroupModel *))success
         failure:(nullable void (^)(ALFError *))failure;


/**
 *    政企分组删除
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupDel:(NSArray *)gids
         success:(nullable void (^)(ALFGroupsModel *))success
         failure:(nullable void (^)(ALFError *))failure;


/**
 *    政企分组重命名
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupRename:(NSString *)gid
          groupName:(NSString *)groupName
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/**
 *    政企分组排序
 *    @param     groupSorts          " gid,gid"
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupSort:(NSString *)groupSorts
          success:(nullable void (^)(void))success
          failure:(nullable void (^)(ALFError *))failure;


/**
 *    分组里添加设备
 *    @param     gid          " gid"
 *    @param     devices          " gid"
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupAddDevice:(NSString *)gid
               devices:(NSArray *)devices
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;


/**
 *    分组里所有设备
 *    @param     gid          " gid"
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)groupDeviceList:(NSString *)gid
                success:(nullable void (^)(NSArray<ALFDeviceInfoModel *> *))success
                failure:(nullable void (^)(ALFError *))failure;



@end

NS_ASSUME_NONNULL_END
