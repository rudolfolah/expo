import { getAssetByID } from '@react-native/assets/registry';
import AssetSourceResolver from './AssetSourceResolver';
let _customSourceTransformer;
export function setCustomSourceTransformer(transformer) {
    _customSourceTransformer = transformer;
}
/**
 * `source` is either a number (opaque type returned by require('./foo.png'))
 * or an `ImageSource` like { uri: '<http location || file path>' }
 */
export default function resolveAssetSource(source) {
    if (typeof source === 'object') {
        return source;
    }
    const asset = getAssetByID(source);
    if (!asset) {
        return undefined;
    }
    const resolver = new AssetSourceResolver(location.origin, null, asset);
    if (_customSourceTransformer) {
        return _customSourceTransformer(resolver);
    }
    return resolver.defaultAsset();
}
Object.defineProperty(resolveAssetSource, 'setCustomSourceTransformer', {
    get() {
        return setCustomSourceTransformer;
    },
});
export const { pickScale } = AssetSourceResolver;
//# sourceMappingURL=resolveAssetSource.web.js.map