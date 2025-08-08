//
//  ALFCloudStorageModel.h
//  ALFLibrary
//
//  Created by HX on 2022/11/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFCloudStoragCognitiveModel : NSObject
@property (nonatomic, strong) NSString *confidence;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *value;
@end

@interface ALFCloudStorageModel : NSObject
@property (nonatomic, strong) NSString *intraPicture;
@property (nonatomic, strong) NSString *m3u8Url;
@property (nonatomic, strong) NSString *fps;
@property (nonatomic, strong) NSString *tsStart;
@property (nonatomic, strong) NSString *tsEnd;
@property (nonatomic, strong) NSString *groupId;
@property (nonatomic, strong) NSString *recordType;
@property (nonatomic, strong) NSArray<ALFCloudStoragCognitiveModel*> *cognitives;

@end



NS_ASSUME_NONNULL_END

