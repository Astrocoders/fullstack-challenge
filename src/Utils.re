type assetURI;
[@bs.val] external requireAssetURI: string => assetURI = "require";

external getURI: assetURI => string = "%identity";

external str: string => React.element = "%identity";