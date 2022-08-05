module Styles = {
    open Css;

    let column =
        style([
            padding2(~v=`px(12),~h=`px(20)),
        ]);
    let hash = 
        style([
                // padding2(~v=`px(12),~h=`px(20)),
                width(`px(500)),
                textOverflow(`ellipsis),
                overflow(`hidden)
            ]);

};

[@react.component]
let make = (~height:int,~hash:string,~timestamp:string,~txn:int) => {
    <tr >
        <th className=Styles.column >{height |> React.int}</th>
        <th className=Styles.column >
            <div className=Styles.hash>
        {
            hash |> React.string
        }
            </div>
        </th>
        <th className=Styles.column >{txn |> React.int}</th>
        <th className=Styles.column >{timestamp |> React.string}</th>
    </tr>
             
}