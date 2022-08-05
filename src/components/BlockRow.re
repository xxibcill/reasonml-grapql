module Styles = {
    open Css;

    let column =
        style([
            fontWeight(`num(100)),
            padding(`px(12)),
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
        <td className=Styles.column >{height |> React.int}</td>
        <td className=Styles.column >
            <div className=Styles.hash>
        {
            hash |> React.string
        }
            </div>
        </td>
        <td className=Styles.column >{txn |> React.int}</td>
        <td className=Styles.column >{timestamp |> MomentRe.moment |> MomentRe.Moment.format("hh:mm:ss DD-MM-YYYY")|> React.string}</td>
    </tr>
             
}