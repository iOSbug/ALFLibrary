//
//  ALFGroupsModel.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFGroupModel : NSObject
@property (nonatomic, strong) NSString * createTs;
@property (nonatomic, strong) NSArray * devices;
@property (nonatomic, strong) NSString * gid;
@property (nonatomic, strong) NSString * groupName;
@property (nonatomic, strong) NSArray * pinner;
@property (nonatomic, strong) NSNumber * isDef;

@end

@interface ALFGroupsModel : NSObject

@property (nonatomic, strong) NSString * groupSorts;
@property (nonatomic, strong) NSArray * groups;

@end

NS_ASSUME_NONNULL_END
