#import <Foundation/Foundation.h>

/**
 * Information about the geo object.
 */
@interface YMKGeoObjectSelectionMetadata : NSObject

/**
 * Object ID.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Layer ID.
 */
@property (nonatomic, readonly, nonnull) NSString *layerId;


+ (nonnull YMKGeoObjectSelectionMetadata *)geoObjectSelectionMetadataWithId:(nonnull NSString *)id
                                                                    layerId:(nonnull NSString *)layerId;


@end

