/*
    Script witten by:
    Ph4sm4
*/

import fetch from "node-fetch";
import reader from 'xlsx'
const file = reader.readFile('C:/Users/I9/Documents/GitHub/Programming/javascript/faceit_scraper/test.xlsx')

const links = ['https://www.faceit.com/pl/csgo/room/1-d1c48858-874d-4975-a6ed-8996c9699a7d', 'https://faceitstats.com/match/1-0bac0e78-4a7c-4074-8395-64a879bd33b6?highlight=Amireczek%27,%27https://faceitstats.com/match/1-6a255931-0709-4532-8d42-7379e6d6bcb2?highlight=derv1ll', 'https://www.faceit.com/pl/csgo/room/1-23613dc7-5920-41ad-844f-194c148435b1', 'https://faceitstats.com/match/1-226ed413-400d-4b8d-8862-40432dc96f36?highlight=boberitooo', 'https://faceitstats.com/match/1-d47fc781-a5be-4235-82bc-7d67898925f1?highlight=Faacik'];
//jak masz np taki link: https://www.faceit.com/en/csgo/room/1-23613dc7-5920-41ad-844f-194c148435b1/scoreboard to id to: 1-23613dc7-5920-41ad-844f-194c148435b1
const KEY = 'f5abf8c7-628c-47d7-a46d-eb4a2788fc26'
const headerFaceit = {
    Authorization: `Bearer ${KEY}`
}
let ct = 1;

async function getTables(matchID) {
    let res;
    await fetch('https://open.faceit.com/data/v4/matches/' + matchID + '/stats', {
        method: 'GET',
        headers: headerFaceit
    })
        .then(function (u) { return u.json(); })
        .then(function (json) {
            res = json;
        })
    console.log(res);

    res.rounds[0]["teams"].forEach(team => {
        let team_name = team.team_stats.Team;
        let players = [];
        team.players.forEach(player => {
            let nickname = player.nickname;
            let hs = player.player_stats['Headshots %'];
            let kills = player.player_stats["Kills"];
            let assists = player.player_stats["Assists"];
            let deaths = player.player_stats["Deaths"];
            let kd = player.player_stats['K/D Ratio'];

            let player_info = {
                nickname: nickname,
                hs: hs,
                kills: kills,
                assists: assists,
                deaths: deaths,
                kd: kd,
            }
            players.push(player_info);

        })
        console.log(players);
        const ws = reader.utils.json_to_sheet(players);
        reader.utils.book_append_sheet(file, ws, ct + '.' + team_name);
        reader.writeFile(file, 'C:/Users/I9/Documents/GitHub/Programming/javascript/faceit_scraper/test.xlsx')
        players = [];
        ct++;
    });

}

links.forEach(link => {
    let matchID = link.substring(link.indexOf('1-'), link.indexOf('1-') + 38);
    console.log(matchID);
    getTables(matchID)
})