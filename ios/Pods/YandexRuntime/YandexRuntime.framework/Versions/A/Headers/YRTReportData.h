#import <YandexRuntime/YRTPlatformBinding.h>

/// @cond EXCLUDE
@interface YRTReportData : YRTPlatformBinding

@property (nonatomic, readonly, nonnull) NSDate *startTime;

@property (nonatomic, readonly, nonnull) NSDate *endTime;

/**
 * Optional property, can be nil.
 */
@property (nonatomic, nullable) NSString *issueId;

- (nonnull NSArray<NSDate *> *)problemMarks;


- (nonnull NSData *)data;


@end
/// @endcond

