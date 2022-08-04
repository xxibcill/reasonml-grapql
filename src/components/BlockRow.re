[@react.component]
let make = (~height:int,~hash:Js.Json.t) => {
    <tr key=Belt.Int.toString(height)>
        <th>{height |> React.int}</th>
        <th>{hash |> Js.Json.stringify |> React.string}</th>
    </tr>
             
}