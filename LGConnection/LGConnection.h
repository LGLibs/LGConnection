//
// LGConnection.h
// LGConnection
//
// SPDX-License-Identifier: MIT
// Copyright (c) 2015 Grigorii Lutkov <grigorii@lutkov.dev>
//

#import <UIKit/UIKit.h>
#import "AFNetworking.h"

@interface LGConnection : NSObject

typedef NS_ENUM(NSUInteger, LGConnectionResponseType)
{
    LGConnectionResponseTypeDATA  = 0,
    LGConnectionResponseTypeJSON  = 1,
    LGConnectionResponseTypeXML   = 2,
    LGConnectionResponseTypePLIST = 3
};

typedef NS_ENUM(NSUInteger, LGConnectionMethod)
{
    LGConnectionMethodPOST = 0,
    LGConnectionMethodGET  = 1,
    LGConnectionMethodJSON = 2
};

@property (assign, nonatomic) BOOL cookiesShouldHandle;
@property (assign, nonatomic) NSTimeInterval timeoutInterval;

- (instancetype)initWithRepeatAfterConnectionLost:(BOOL)repeat;

/** Do not forget about weak referens to self for connectionLostHandler and connectionRestoreHandler blocks */
- (instancetype)initWithRepeatAfterConnectionLost:(BOOL)repeat
                            connectionLostHandler:(void(^)())connectionLostHandler
                         connectionRestoreHandler:(void(^)())connectionRestoreHandler;

+ (instancetype)connectionWithRepeatAfterConnectionLost:(BOOL)repeat;

/** Do not forget about weak referens to self for connectionLostHandler and connectionRestoreHandler blocks */
+ (instancetype)connectionWithRepeatAfterConnectionLost:(BOOL)repeat
                                  connectionLostHandler:(void(^)())connectionLostHandler
                               connectionRestoreHandler:(void(^)())connectionRestoreHandler;

#pragma mark - Get / Post

- (void)sendRequestToUrl:(NSURL *)url
                  method:(LGConnectionMethod)method
              parameters:(id)parameters
            responseType:(LGConnectionResponseType)responseType
            setupHandler:(void(^)(AFHTTPRequestOperationManager *manager))setupHandler
       completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

#pragma mark - Multipart

- (void)sendMultipartRequestToUrl:(NSURL *)url
                       parameters:(id)parameters
                             name:(NSString *)name
                             data:(NSData *)data
                    fileExtension:(NSString *)fileExtension
                     responseType:(LGConnectionResponseType)responseType
                  progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

- (void)sendMultipartRequestToUrl:(NSURL *)url
                       parameters:(id)parameters
                             name:(NSString *)name
                        dataArray:(NSArray *)dataArray
                    fileExtension:(NSString *)fileExtension
                     responseType:(LGConnectionResponseType)responseType
                  progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

- (void)sendMultipartRequestToUrl:(NSURL *)url
                       parameters:(id)parameters
                             name:(NSString *)name
                    fileUrlsArray:(NSArray *)fileUrlsArray
                     responseType:(LGConnectionResponseType)responseType
                  progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

- (void)sendMultipartRequestToUrl:(NSURL *)url
                       parameters:(id)parameters
                             name:(NSString *)name
                   filePathsArray:(NSArray *)filePathsArray
                     responseType:(LGConnectionResponseType)responseType
                  progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

- (void)sendMultipartRequestToUrl:(NSURL *)url
                       parameters:(id)parameters
        constructingBodyWithBlock:(void(^)(id<AFMultipartFormData> formData))constructingBodyWithBlock
                     responseType:(LGConnectionResponseType)responseType
                  progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                completionHandler:(void(^)(NSError *error, id responseObject))completionHandler;

#pragma mark - Download

- (void)downloadFileFromURL:(NSURL *)url
                 toLocalUrl:(NSURL *)localUrl
            progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
          completionHandler:(void(^)(NSError *error))completionHandler;

- (void)downloadFileWithModifiedControlFromURL:(NSURL *)url
                                    toLocalUrl:(NSURL *)localUrl
                               progressHandler:(void(^)(long long totalBytesExpectedToRead, long long totalBytesRead, float progress, NSUInteger downloadPercentage))progressHandler
                             completionHandler:(void(^)(NSError *error, BOOL isModified))completionHandler;

#pragma mark - Cancel

- (void)cancelAllOperations;

@end
