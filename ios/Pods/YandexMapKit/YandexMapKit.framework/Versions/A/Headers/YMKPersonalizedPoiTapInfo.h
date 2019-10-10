#import <Foundation/Foundation.h>

/// @cond EXCLUDE
@interface YMKPersonalizedPoiTapInfo : NSObject

/**
 * Source ID of the tapped POI from the renderer.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Type of the tapped POI, e.g. "urban-foodservice-restaurant".
 */
@property (nonatomic, readonly, nonnull) NSString *ftType;

/**
 * Category of the tapped POI, e.g. "bars".
 */
@property (nonatomic, readonly, nonnull) NSString *rubricClass;

/**
 * Corresponding ID of the category.
 */
@property (nonatomic, readonly, nonnull) NSString *rubricId;

/**
 * URI of the tapped POI in the format "ymapsbm1://org?oid=...".
 */
@property (nonatomic, readonly, nonnull) NSString *uri;

/**
 * Title of the tapped POI.
 */
@property (nonatomic, readonly, nonnull) NSString *title;


+ (nonnull YMKPersonalizedPoiTapInfo *)personalizedPoiTapInfoWithId:(nonnull NSString *)id
                                                             ftType:(nonnull NSString *)ftType
                                                        rubricClass:(nonnull NSString *)rubricClass
                                                           rubricId:(nonnull NSString *)rubricId
                                                                uri:(nonnull NSString *)uri
                                                              title:(nonnull NSString *)title;


@end
/// @endcond

