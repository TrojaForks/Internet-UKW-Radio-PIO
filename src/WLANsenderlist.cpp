#include "MakeRadio.h"

void setup_senderList()
{
  //sender.begin("senderlist", false);

  stationname[0] = "Radio Wien";
  stationurl[0] = "https://orf-live.ors-shoutcast.at/wie-q1a.m3u";

  stationname[1] = "Radio OÖ";
  stationurl[1] = "https://orf-live.ors-shoutcast.at/ooe-q1a.m3u";

  stationname[2] = "HIT RTL-Oldies";
  stationurl[2] = "https://web.radio.hitradio-rtl.de/hrrtl-oldies/stream/mp3";

  stationname[3] = "HIT RTL-Schlager";
  stationurl[3] = "https://web.radio.hitradio-rtl.de/hrrtl-schlager/stream/mp3";

  stationname[4] = "HIT RTL-80er";
  stationurl[4] = "https://web.radio.hitradio-rtl.de/hrrtl-80er/stream/mp3";

  stationname[5] = "HIT RTL-PartyMix";
  stationurl[5] = "https://web.radio.hitradio-rtl.de/hrrtl-maxis/stream/mp3";

  stationname[6] = "Arabella Oldies";
  stationurl[6] = "https://frontend.streams.arabella.at/arabella-goldenoldies/stream/mp3?aggregator=arabella-playlistfile";

  stationname[7] = "HIT RTL-Xmas";
  stationurl[7] = "https://web.radio.hitradio-rtl.de/hrrtl-xmas/stream/mp3";

  stationname[8] = "HIT RTL-Xmas Hits";
  stationurl[8] = "https://stream.rtlradio.de/xms-greatesthits/mp3-128/radiode";


  //  https://www.chip.de/artikel/Webradio-Live-Stream-Alle-Sender-im-ueberblick_139924359.html

  stationname[9] = "Schlager";
  stationurl[9] = "http://stream.laut.fm/schlager.m3u";

  // https://marijanbloggt.at/2023/04/links-zu-streams-der-oesterreichischen-radiosender/120920
  // https://static.arabella.at/streamadressen/


  stationname[10] = "Radio NÖ";
  stationurl[10] = "https://orf-live.ors-shoutcast.at/noe-q1a.m3u";

  stationname[11] = "Ö1";
  stationurl[11] = "https://orf-live.ors-shoutcast.at/oe1-q1a.m3u";

  stationname[12] = "Ö3";
  stationurl[12] = "https://orf-live.ors-shoutcast.at/oe3-q1a.m3u";

  stationname[13] = "Arabella Austropop";
  stationurl[13] = "https://frontend.streams.arabella.at/arabella-austropop/stream/mp3?aggregator=arabella-playlistfile";

  stationurl[14] = "UKW";
  stationname[14] = "UKW";
}
