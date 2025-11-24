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
*    Singleton
*/
+ (instancetype)shared;


/**
 *   Enterprise Group List
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)fetchGroupList:(nullable void (^)(ALFGroupsModel *))success
               failure:(nullable void (^)(ALFError *))failure;


/**
 *    Enterprise Group Add
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupAdd:(NSString *)groupName
         success:(nullable void (^)(ALFGroupModel *))success
         failure:(nullable void (^)(ALFError *))failure;


/**
 *    Enterprise Group Delete
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupDel:(NSArray *)gids
         success:(nullable void (^)(ALFGroupsModel *))success
         failure:(nullable void (^)(ALFError *))failure;


/**
 *    Enterprise Group Rename
 *
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupRename:(NSString *)gid
          groupName:(NSString *)groupName
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/**
 *    Enterprise Group Sort
 *    @param     groupSorts          " gid,gid"
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupSort:(NSString *)groupSorts
          success:(nullable void (^)(void))success
          failure:(nullable void (^)(ALFError *))failure;


/**
 *    Add devices to group
 *    @param     gid          " gid"
 *    @param     devices          " gid"
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupAddDevice:(NSString *)gid
               devices:(NSArray *)devices
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;


/**
 *    All devices in the group
 *    @param     gid          " gid"
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)groupDeviceList:(NSString *)gid
                success:(nullable void (^)(NSArray<ALFDeviceInfoModel *> *))success
                failure:(nullable void (^)(ALFError *))failure;



@end

NS_ASSUME_NONNULL_END
