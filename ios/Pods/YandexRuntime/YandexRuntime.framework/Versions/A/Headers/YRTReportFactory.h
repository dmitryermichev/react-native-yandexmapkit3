#import <YandexRuntime/YRTPlatformBinding.h>

@class YRTReportData;

/// @cond EXCLUDE
@interface YRTReportFactory : YRTPlatformBinding

- (nonnull YRTReportData *)createReportDataWithData:(nonnull NSData *)data;


@end
/// @endcond

