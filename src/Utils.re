type assetURI;
[@bs.val] external requireAssetURI: string => assetURI = "require";

[@bs.val] external requireStyle: string => unit = "require";

external getURI: assetURI => string = "%identity";

external str: string => React.element = "%identity";