#import <YandexMapKit/YMKGlyphsGlyphUrlProvider.h>
#import <YandexRuntime/YRTPlatformBinding.h>

/// @cond EXCLUDE
@interface YMKGlyphsDefaultUrlProvider : YRTPlatformBinding<YMKGlyphsGlyphUrlProvider>

- (NSString *)formatUrlWithFontId:(NSString *)fontId
                            range:(YMKGlyphsGlyphIdRange *)range;

- (void)setUrlPattern:(NSString *)urlPattern;

@end
/// @endcond