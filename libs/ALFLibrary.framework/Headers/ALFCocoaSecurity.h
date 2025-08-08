/*
 CocoaSecurity  1.1

 Created by Kelp on 12/5/12.
 Copyright (c) 2012 Kelp http://kelp.phate.org/
 MIT License
 
 CocoaSecurity is core. It provides AES encrypt, AES decrypt, Hash(MD5, HmacMD5, SHA1~SHA512, HmacSHA1~HmacSHA512) messages.
*/

#import <Foundation/Foundation.h>
#import <Foundation/NSException.h>


#pragma mark - CocoaSecurityResult
@interface ALFCocoaSecurityResult : NSObject

@property (strong, nonatomic, readonly) NSData *data;
@property (strong, nonatomic, readonly) NSString *utf8String;
@property (strong, nonatomic, readonly) NSString *hex;
@property (strong, nonatomic, readonly) NSString *hexLower;
@property (strong, nonatomic, readonly) NSString *base64;

- (id)initWithBytes:(unsigned char[])initData length:(NSUInteger)length;

@end


#pragma mark - CocoaSecurity
@interface ALFCocoaSecurity : NSObject
#pragma mark - AES Encrypt
+ (ALFCocoaSecurityResult *)aesEncrypt:(NSString *)data key:(NSString *)key;
+ (ALFCocoaSecurityResult *)aesEncrypt:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (ALFCocoaSecurityResult *)aesEncrypt:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (ALFCocoaSecurityResult *)aesEncryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;
#pragma mark AES Decrypt
+ (ALFCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data key:(NSString *)key;
+ (ALFCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (ALFCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (ALFCocoaSecurityResult *)aesDecryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;

#pragma mark - MD5
+ (ALFCocoaSecurityResult *)md5:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)md5WithData:(NSData *)hashData;
#pragma mark HMAC-MD5
+ (ALFCocoaSecurityResult *)hmacMd5:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacMd5WithData:(NSData *)hashData hmacKey:(NSString *)key;

#pragma mark - SHA
+ (ALFCocoaSecurityResult *)sha1:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)sha1WithData:(NSData *)hashData;
+ (ALFCocoaSecurityResult *)sha224:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)sha224WithData:(NSData *)hashData;
+ (ALFCocoaSecurityResult *)sha256:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)sha256WithData:(NSData *)hashData;
+ (ALFCocoaSecurityResult *)sha384:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)sha384WithData:(NSData *)hashData;
+ (ALFCocoaSecurityResult *)sha512:(NSString *)hashString;
+ (ALFCocoaSecurityResult *)sha512WithData:(NSData *)hashData;
#pragma mark HMAC-SHA
+ (ALFCocoaSecurityResult *)hmacSha1:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha1WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha224:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha224WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha256:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha256WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha384:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha384WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha512:(NSString *)hashString hmacKey:(NSString *)key;
+ (ALFCocoaSecurityResult *)hmacSha512WithData:(NSData *)hashData hmacKey:(NSString *)key;
@end


#pragma mark - CocoaSecurityEncoder
@interface ALFCocoaSecurityEncoder : NSObject
- (NSString *)base64:(NSData *)data;
- (NSString *)hex:(NSData *)data useLower:(BOOL)isOutputLower;
@end


#pragma mark - CocoaSecurityDecoder
@interface ALFCocoaSecurityDecoder : NSObject
- (NSData *)base64:(NSString *)data;
- (NSData *)hex:(NSString *)data;
@end
