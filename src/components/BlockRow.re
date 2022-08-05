module Styles = {
    open Css;

    let column =
        style([
            padding2(~v=`px(12),~h=`px(20))
        ]);
};

[@react.component]
let make = (~height:int,~hash:Js.Json.t) => {
    <tr >
        <th className=Styles.column >{height |> React.int}</th>
        <th className=Styles.column >{hash |> Js.Json.stringify |> React.string}</th>
    </tr>
             
}