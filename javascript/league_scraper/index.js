/*
    Script witten by:
    Ph4sm4
*/

import fetch from "node-fetch";
import reader from 'xlsx'
const file = reader.readFile('C:/Users/I9/Documents/GitHub/Programming/javascript/league_scraper/test.xlsx')

const matchID = 'EUN1_3033323052';
const KEY = 'RGAPI-9fd51736-e0f4-42f4-84d0-262df4e9fffa'
const headerLeague = {
    method: 'GET',
    redirect: 'follow'
}

async function getTables(matchID) {
    let res;
    await fetch('https://europe.api.riotgames.com/lol/match/v5/matches/' + matchID + '?api_key=' + KEY, headerLeague)
        .then(function (u) { return u.json(); })
        .then(function (json) {
            res = json;
        })
    console.log(res);


    // const ws = reader.utils.json_to_sheet(players);
    // reader.utils.book_append_sheet(file, ws, team_name);
    // reader.writeFile(file, 'C:/Users/I9/Documents/GitHub/Programming/javascript/league_scraper/test.xlsx')

}

getTables(matchID)