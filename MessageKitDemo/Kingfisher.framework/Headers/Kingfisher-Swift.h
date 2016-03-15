// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.15 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSMutableURLRequest;
@class NSURLSessionConfiguration;
@protocol ImageDownloaderDelegate;


/// ImageDownloader represents a downloading manager for requesting the image with a URL from server.
SWIFT_CLASS("_TtC10Kingfisher15ImageDownloader")
@interface ImageDownloader : NSObject

/// This closure will be applied to the image download request before it being sent. You can modify the request for some customizing purpose, like adding auth token to the header or do a url mapping.
@property (nonatomic, copy) void (^ __nullable requestModifier)(NSMutableURLRequest * __nonnull);

/// The duration before the download is timeout. Default is 15 seconds.
@property (nonatomic) NSTimeInterval downloadTimeout;

/// A set of trusted hosts when receiving server trust challenges. A challenge with host name contained in this set will be ignored. You can use this set to specify the self-signed site.
@property (nonatomic, copy) NSSet<NSString *> * __nullable trustedHosts;

/// Use this to set supply a configuration for the downloader. By default, NSURLSessionConfiguration.ephemeralSessionConfiguration() will be used. You could change the configuration before a downloaing task starts. A configuration without persistent storage for caches is requsted for downloader working correctly.
@property (nonatomic, strong) NSURLSessionConfiguration * __nonnull sessionConfiguration;

/// Whether the download requests should use pipeling or not. Default is false.
@property (nonatomic) BOOL requestsUsePipeling;

/// Delegate of this ImageDownloader object. See ImageDownloaderDelegate protocol for more.
@property (nonatomic, weak) id <ImageDownloaderDelegate> __nullable delegate;

/// The default downloader.
+ (ImageDownloader * __nonnull)defaultDownloader;

/// Init a downloader with name.
///
/// \param name The name for the downloader. It should not be empty.
///
/// \returns  The downloader object.
- (nonnull instancetype)initWithName:(NSString * __nonnull)name OBJC_DESIGNATED_INITIALIZER;
@end


@interface ImageDownloader (SWIFT_EXTENSION(Kingfisher))
@end

@class UIImage;
@class NSURL;
@class NSURLResponse;


/// Protocol of ImageDownloader.
SWIFT_PROTOCOL("_TtP10Kingfisher23ImageDownloaderDelegate_")
@protocol ImageDownloaderDelegate
@optional

/// Called when the ImageDownloader object successfully downloaded an image from specified URL.
///
/// \param downloader The <code>ImageDownloader
/// </code> object finishes the downloading.
///
/// \param image Downloaded image.
///
/// \param URL URL of the original request URL.
///
/// \param response The response object of the downloading process.
- (void)imageDownloader:(ImageDownloader * __nonnull)downloader didDownloadImage:(UIImage * __nonnull)image forURL:(NSURL * __nonnull)URL withResponse:(NSURLResponse * __nonnull)response;
@end


@interface NSData (SWIFT_EXTENSION(Kingfisher))
@end


@interface NSMutableData (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIActivityIndicatorView (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))

/// Cancel the image download task bounded to the image view if it is running. Nothing will happen if the downloading has already finished.
- (void)kf_cancelImageDownloadTask;

/// Cancel the background image download task bounded to the image view if it is running. Nothing will happen if the downloading has already finished.
- (void)kf_cancelBackgroundImageDownloadTask;
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))

/// Get the image URL binded to this button for a specified state.
///
/// \param state The state that uses the specified image.
///
/// \returns  Current URL for image.
- (NSURL * __nullable)kf_webURLForState:(UIControlState)state;
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))

/// Get the background image URL binded to this button for a specified state.
///
/// \param state The state that uses the specified background image.
///
/// \returns  Current URL for background image.
- (NSURL * __nullable)kf_backgroundWebURLForState:(UIControlState)state;
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))

/// Normalize the image. This method will try to redraw an image with orientation and scale considered.
///
/// \returns  The normalized image with orientation set to up and correct scale.
- (UIImage * __nonnull)kf_normalizedImage;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))

/// Cancel the image download task bounded to the image view if it is running. Nothing will happen if the downloading has already finished.
- (void)kf_cancelDownloadTask;
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))

/// Get the image URL binded to this image view.
@property (nonatomic, readonly, strong) NSURL * __nullable kf_webURL;

/// Whether show an animating indicator when the image view is loading an image or not. Default is false.
@property (nonatomic) BOOL kf_showIndicatorWhenLoading;

/// The indicator view showing when loading. This will be nil if kf_showIndicatorWhenLoading is false. You may want to use this to set the indicator style or color when you set kf_showIndicatorWhenLoading to true.
@property (nonatomic, readonly, strong) UIActivityIndicatorView * __nullable kf_indicator;
@end

#pragma clang diagnostic pop