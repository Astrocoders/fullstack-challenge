type asset;
[@bs.val] external requireAsset: string => asset = "require";

[@bs.val] external requireStyle: string => unit = "require";

external getURI: asset => string = "%identity";

external str: string => React.element = "%identity";
