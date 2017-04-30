// GENERATED FILE: inline version sources
#ifndef TILEMESH_HPP
#define TILEMESH_HPP
#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <vector>
#ifndef TILEMESH_FEATURES_HPP
#define TILEMESH_FEATURES_HPP
#include <map>
#include <stdint.h>
#include <string.h>

namespace tilemesh {
struct cmp_str {
  bool operator()(char const *a, char const *b) {
    return strcmp(a, b) < 0;
  }
};
typedef std::map<const char *,size_t,cmp_str> Features;
typedef std::map<const char *,size_t,cmp_str>::const_iterator FeaturesIterator;
void load_features (Features *features) {
  (*features)["aerialway.cable_car"] = 1;
  (*features)["aerialway.canopy"] = 2;
  (*features)["aerialway.chair_lift"] = 3;
  (*features)["aerialway.drag_lift"] = 4;
  (*features)["aerialway.gondola"] = 5;
  (*features)["aerialway.goods"] = 6;
  (*features)["aerialway.j-bar"] = 7;
  (*features)["aerialway.magic_carpet"] = 8;
  (*features)["aerialway.mixed_lift"] = 9;
  (*features)["aerialway.platter"] = 10;
  (*features)["aerialway.pylon"] = 11;
  (*features)["aerialway.rope_tow"] = 12;
  (*features)["aerialway.station"] = 13;
  (*features)["aerialway.t-bar"] = 14;
  (*features)["aerialway.zip_line"] = 15;
  (*features)["aerialway"] = 16;
  (*features)["amenity.animal_boarding"] = 17;
  (*features)["amenity.animal_shelter"] = 18;
  (*features)["amenity.arts_centre"] = 19;
  (*features)["amenity.atm"] = 20;
  (*features)["amenity.baby_hatch"] = 21;
  (*features)["amenity.baking_oven"] = 22;
  (*features)["amenity.bank"] = 23;
  (*features)["amenity.bar"] = 24;
  (*features)["amenity.bbq"] = 25;
  (*features)["amenity.bench"] = 26;
  (*features)["amenity.bicycle parking"] = 27;
  (*features)["amenity.bicycle rental"] = 28;
  (*features)["amenity.bicycle_repair_station"] = 29;
  (*features)["amenity.biergarten"] = 30;
  (*features)["amenity.boat_sharing"] = 31;
  (*features)["amenity.brothel"] = 32;
  (*features)["amenity.bureau de change"] = 33;
  (*features)["amenity.bus_station"] = 34;
  (*features)["amenity.cafe"] = 35;
  (*features)["amenity.car rental"] = 36;
  (*features)["amenity.car sharing"] = 37;
  (*features)["amenity.car wash"] = 38;
  (*features)["amenity.casino"] = 39;
  (*features)["amenity.charging_station"] = 40;
  (*features)["amenity.cinema"] = 41;
  (*features)["amenity.clinic"] = 42;
  (*features)["amenity.clock"] = 43;
  (*features)["amenity.college"] = 44;
  (*features)["amenity.community_centre"] = 45;
  (*features)["amenity.courthouse"] = 46;
  (*features)["amenity.coworking_space"] = 47;
  (*features)["amenity.crematorium"] = 48;
  (*features)["amenity.crypt"] = 49;
  (*features)["amenity.dentist"] = 50;
  (*features)["amenity.dive_centre"] = 51;
  (*features)["amenity.doctors"] = 52;
  (*features)["amenity.dojo"] = 53;
  (*features)["amenity.drinking_water"] = 54;
  (*features)["amenity.driving_school"] = 55;
  (*features)["amenity.embassy"] = 56;
  (*features)["amenity.fast food"] = 57;
  (*features)["amenity.ferry_terminal"] = 58;
  (*features)["amenity.firepit"] = 59;
  (*features)["amenity.fire_station"] = 60;
  (*features)["amenity.food court"] = 61;
  (*features)["amenity.fountain"] = 62;
  (*features)["amenity.fuel"] = 63;
  (*features)["amenity.gambling"] = 64;
  (*features)["amenity.game_feeding"] = 65;
  (*features)["amenity.grave_yard"] = 66;
  (*features)["amenity.grit_bin"] = 67;
  (*features)["amenity.gym"] = 68;
  (*features)["amenity.hospital"] = 69;
  (*features)["amenity.hunting_stand"] = 70;
  (*features)["amenity.ice_cream"] = 71;
  (*features)["amenity.internet_cafe"] = 72;
  (*features)["amenity.kindergarten"] = 73;
  (*features)["amenity.kneipp_water_cure"] = 74;
  (*features)["amenity.language_school"] = 75;
  (*features)["amenity.library"] = 76;
  (*features)["amenity.marketplace"] = 77;
  (*features)["amenity.motorcycle parking"] = 78;
  (*features)["amenity.music_school"] = 79;
  (*features)["amenity.nightclub"] = 80;
  (*features)["amenity.nursing_home"] = 81;
  (*features)["amenity.parking"] = 82;
  (*features)["amenity.parking_entrance"] = 83;
  (*features)["amenity.parking_space"] = 84;
  (*features)["amenity.pharmacy"] = 85;
  (*features)["amenity.photo_booth"] = 86;
  (*features)["amenity.place of worship"] = 87;
  (*features)["amenity.place of worship|the article"] = 88;
  (*features)["amenity.planetarium"] = 89;
  (*features)["amenity.police"] = 90;
  (*features)["amenity.post_box"] = 91;
  (*features)["amenity.post_office"] = 92;
  (*features)["amenity.prison"] = 93;
  (*features)["amenity.pub"] = 94;
  (*features)["amenity.public_bookcase"] = 95;
  (*features)["amenity.public_building"] = 96;
  (*features)["amenity.ranger_station"] = 97;
  (*features)["amenity.recycling"] = 98;
  (*features)["amenity.rescue_station"] = 99;
  (*features)["amenity.restaurant"] = 100;
  (*features)["amenity.sauna"] = 101;
  (*features)["amenity.school"] = 102;
  (*features)["amenity.shelter"] = 103;
  (*features)["amenity.shower"] = 104;
  (*features)["amenity.social_centre"] = 105;
  (*features)["amenity.social_facility"] = 106;
  (*features)["amenity.stripclub"] = 107;
  (*features)["amenity.stripclub| amenity=stripclub"] = 108;
  (*features)["amenity.studio"] = 109;
  (*features)["amenity.swingerclub"] = 110;
  (*features)["amenity.table"] = 111;
  (*features)["amenity.taxi"] = 112;
  (*features)["amenity.telephone"] = 113;
  (*features)["amenity.theatre"] = 114;
  (*features)["amenity.toilets"] = 115;
  (*features)["amenity.townhall"] = 116;
  (*features)["amenity.university"] = 117;
  (*features)["amenity.vending_machine"] = 118;
  (*features)["amenity.veterinary"] = 119;
  (*features)["amenity.waste_basket"] = 120;
  (*features)["amenity.waste_disposal"] = 121;
  (*features)["amenity.waste_transfer_station"] = 122;
  (*features)["amenity.watering_place"] = 123;
  (*features)["amenity.water_point"] = 124;
  (*features)["amenity"] = 125;
  (*features)["barrier.block"] = 126;
  (*features)["barrier.bollard"] = 127;
  (*features)["barrier.border_control"] = 128;
  (*features)["barrier.bump_gate"] = 129;
  (*features)["barrier.bus_trap"] = 130;
  (*features)["barrier.cable_barrier"] = 131;
  (*features)["barrier.cattle_grid"] = 132;
  (*features)["barrier.chain"] = 133;
  (*features)["barrier.city_wall"] = 134;
  (*features)["barrier.cycle_barrier"] = 135;
  (*features)["barrier.debris"] = 136;
  (*features)["barrier.ditch"] = 137;
  (*features)["barrier.entrance"] = 138;
  (*features)["barrier.fence"] = 139;
  (*features)["barrier.full-height_turnstile"] = 140;
  (*features)["barrier.gate"] = 141;
  (*features)["barrier.guard_rail"] = 142;
  (*features)["barrier.hampshire_gate"] = 143;
  (*features)["barrier.handrail"] = 144;
  (*features)["barrier.hedge"] = 145;
  (*features)["barrier.height_restrictor"] = 146;
  (*features)["barrier.horse_stile"] = 147;
  (*features)["barrier.jersey_barrier"] = 148;
  (*features)["barrier.kent_carriage_gap"] = 149;
  (*features)["barrier.kerb"] = 150;
  (*features)["barrier.kissing_gate"] = 151;
  (*features)["barrier.lift_gate"] = 152;
  (*features)["barrier.log"] = 153;
  (*features)["barrier.motorcycle_barrier"] = 154;
  (*features)["barrier.retaining_wall"] = 155;
  (*features)["barrier.rope"] = 156;
  (*features)["barrier.sally_port"] = 157;
  (*features)["barrier.spikes"] = 158;
  (*features)["barrier.stile"] = 159;
  (*features)["barrier.sump_buster"] = 160;
  (*features)["barrier.swing_gate"] = 161;
  (*features)["barrier.tank_trap"] = 162;
  (*features)["barrier.toll_booth"] = 163;
  (*features)["barrier.turnstile"] = 164;
  (*features)["barrier.wall"] = 165;
  (*features)["barrier.yes"] = 166;
  (*features)["barrier"] = 167;
  (*features)["boundary.administrative"] = 168;
  (*features)["boundary.historic"] = 169;
  (*features)["boundary.maritime"] = 170;
  (*features)["boundary.national_park"] = 171;
  (*features)["boundary.political"] = 172;
  (*features)["boundary.postal_code"] = 173;
  (*features)["boundary.protected_area"] = 174;
  (*features)["boundary.religious_administration"] = 175;
  (*features)["boundary"] = 176;
  (*features)["highway.bridleway"] = 177;
  (*features)["highway.bus guideway"] = 178;
  (*features)["highway.bus_stop"] = 179;
  (*features)["highway.construction"] = 180;
  (*features)["highway.crossing"] = 181;
  (*features)["highway.cycleway"] = 182;
  (*features)["highway.elevator"] = 183;
  (*features)["highway.emergency_access_point"] = 184;
  (*features)["highway.escape"] = 185;
  (*features)["highway.footway"] = 186;
  (*features)["highway.give_way"] = 187;
  (*features)["highway.living_street"] = 188;
  (*features)["highway.mini_roundabout"] = 189;
  (*features)["highway.motorway"] = 190;
  (*features)["highway.motorway_junction"] = 191;
  (*features)["highway.motorway_link"] = 192;
  (*features)["highway.passing_place"] = 193;
  (*features)["highway.path"] = 194;
  (*features)["highway.pedestrian"] = 195;
  (*features)["highway.primary"] = 196;
  (*features)["highway.primary_link"] = 197;
  (*features)["highway.proposed"] = 198;
  (*features)["highway.raceway"] = 199;
  (*features)["highway.residential"] = 200;
  (*features)["highway.rest_area"] = 201;
  (*features)["highway.road"] = 202;
  (*features)["highway.secondary"] = 203;
  (*features)["highway.secondary_link"] = 204;
  (*features)["highway.service"] = 205;
  (*features)["highway.services"] = 206;
  (*features)["highway.speed_camera"] = 207;
  (*features)["highway.steps"] = 208;
  (*features)["highway.stop"] = 209;
  (*features)["highway.street_lamp"] = 210;
  (*features)["highway.tertiary"] = 211;
  (*features)["highway.tertiary_link"] = 212;
  (*features)["highway.track"] = 213;
  (*features)["highway.traffic_signals"] = 214;
  (*features)["highway.trunk_link"] = 215;
  (*features)["highway.turning_circle"] = 216;
  (*features)["highway.unclassified"] = 217;
  (*features)["highway"] = 218;
  (*features)["historic.aircraft"] = 219;
  (*features)["historic.aqueduct"] = 220;
  (*features)["historic.archaeological_site"] = 221;
  (*features)["historic.battlefield"] = 222;
  (*features)["historic.boundary_stone"] = 223;
  (*features)["historic.building"] = 224;
  (*features)["historic.cannon"] = 225;
  (*features)["historic.castle"] = 226;
  (*features)["historic.city_gate"] = 227;
  (*features)["historic.citywalls"] = 228;
  (*features)["historic.farm"] = 229;
  (*features)["historic.fort"] = 230;
  (*features)["historic.gallows"] = 231;
  (*features)["historic.highwater_mark"] = 232;
  (*features)["historic.locomotive"] = 233;
  (*features)["historic.manor"] = 234;
  (*features)["historic.memorial"] = 235;
  (*features)["historic.milestone"] = 236;
  (*features)["historic.monastery"] = 237;
  (*features)["historic.monument"] = 238;
  (*features)["historic.optical_telegraph"] = 239;
  (*features)["historic.pillory"] = 240;
  (*features)["historic.ruins"] = 241;
  (*features)["historic.rune_stone"] = 242;
  (*features)["historic.ship"] = 243;
  (*features)["historic.tomb"] = 244;
  (*features)["historic.tree_shrine"] = 245;
  (*features)["historic.wayside_cross"] = 246;
  (*features)["historic.wayside_shrine"] = 247;
  (*features)["historic.wreck"] = 248;
  (*features)["historic.yes"] = 249;
  (*features)["historic"] = 250;
  (*features)["landuse.conservation"] = 251;
  (*features)["landuse.pasture"] = 252;
  (*features)["landuse.peat_cutting"] = 253;
  (*features)["landuse"] = 254;
  (*features)["place.allotments"] = 255;
  (*features)["place.borough"] = 256;
  (*features)["place.city"] = 257;
  (*features)["place.city_block"] = 258;
  (*features)["place.continent"] = 259;
  (*features)["place.country"] = 260;
  (*features)["place.county"] = 261;
  (*features)["place.district"] = 262;
  (*features)["place.farm"] = 263;
  (*features)["place.hamlet"] = 264;
  (*features)["place.isolated_dwelling"] = 265;
  (*features)["place.locality"] = 266;
  (*features)["place.municipality"] = 267;
  (*features)["place.neighbourhood"] = 268;
  (*features)["place.plot"] = 269;
  (*features)["place.province"] = 270;
  (*features)["place.quarter"] = 271;
  (*features)["place.region"] = 272;
  (*features)["place.state"] = 273;
  (*features)["place.suburb"] = 274;
  (*features)["place.town"] = 275;
  (*features)["place.village"] = 276;
  (*features)["place"] = 277;
  (*features)["railway.abandoned"] = 278;
  (*features)["railway.buffer_stop"] = 279;
  (*features)["railway.construction"] = 280;
  (*features)["railway.crossing"] = 281;
  (*features)["railway.derail"] = 282;
  (*features)["railway.disused"] = 283;
  (*features)["railway.funicular"] = 284;
  (*features)["railway.halt"] = 285;
  (*features)["railway.level_crossing"] = 286;
  (*features)["railway.light_rail"] = 287;
  (*features)["railway.miniature"] = 288;
  (*features)["railway.monorail"] = 289;
  (*features)["railway.narrow_gauge"] = 290;
  (*features)["railway.platform"] = 291;
  (*features)["railway.preserved"] = 292;
  (*features)["railway.rail"] = 293;
  (*features)["railway.railway_crossing"] = 294;
  (*features)["railway.roundhouse"] = 295;
  (*features)["railway.signal"] = 296;
  (*features)["railway.station"] = 297;
  (*features)["railway.subway"] = 298;
  (*features)["railway.subway_entrance"] = 299;
  (*features)["railway.switch"] = 300;
  (*features)["railway.tram"] = 301;
  (*features)["railway.tram_stop"] = 302;
  (*features)["railway.traverser"] = 303;
  (*features)["railway.turntable"] = 304;
  (*features)["railway"] = 305;
  (*features)["shop.agrarian"] = 306;
  (*features)["shop.alcohol"] = 307;
  (*features)["shop.anime"] = 308;
  (*features)["shop.antiques"] = 309;
  (*features)["shop.art"] = 310;
  (*features)["shop.baby_goods"] = 311;
  (*features)["shop.bag"] = 312;
  (*features)["shop.bakery"] = 313;
  (*features)["shop.bathroom_furnishing"] = 314;
  (*features)["shop.beauty"] = 315;
  (*features)["shop.bed"] = 316;
  (*features)["shop.beverages"] = 317;
  (*features)["shop.bicycle"] = 318;
  (*features)["shop.bookmaker"] = 319;
  (*features)["shop.books"] = 320;
  (*features)["shop.boutique"] = 321;
  (*features)["shop.brewing_supplies"] = 322;
  (*features)["shop.butcher"] = 323;
  (*features)["shop.camera"] = 324;
  (*features)["shop.candles"] = 325;
  (*features)["shop.car"] = 326;
  (*features)["shop.car_parts"] = 327;
  (*features)["shop.carpet"] = 328;
  (*features)["shop.car_repair"] = 329;
  (*features)["shop.charity"] = 330;
  (*features)["shop.cheese"] = 331;
  (*features)["shop.chemist"] = 332;
  (*features)["shop.chocolate"] = 333;
  (*features)["shop.clothes"] = 334;
  (*features)["shop.coffee"] = 335;
  (*features)["shop.collector"] = 336;
  (*features)["shop.computer"] = 337;
  (*features)["shop.confectionery"] = 338;
  (*features)["shop.convenience"] = 339;
  (*features)["shop.copyshop"] = 340;
  (*features)["shop.cosmetics"] = 341;
  (*features)["shop.craft"] = 342;
  (*features)["shop.curtain"] = 343;
  (*features)["shop.dairy"] = 344;
  (*features)["shop.deli"] = 345;
  (*features)["shop.department_store"] = 346;
  (*features)["shop.doityourself"] = 347;
  (*features)["shop.dry cleaning"] = 348;
  (*features)["shop.e-cigarette"] = 349;
  (*features)["shop.electrical"] = 350;
  (*features)["shop.electronics"] = 351;
  (*features)["shop.energy"] = 352;
  (*features)["shop.erotic"] = 353;
  (*features)["shop.fabric"] = 354;
  (*features)["shop.farm"] = 355;
  (*features)["shop.fashion"] = 356;
  (*features)["shop.fireplace"] = 357;
  (*features)["shop.fishing"] = 358;
  (*features)["shop.florist"] = 359;
  (*features)["shop.frame"] = 360;
  (*features)["shop.free_flying"] = 361;
  (*features)["shop.fuel"] = 362;
  (*features)["shop.funeral_directors"] = 363;
  (*features)["shop.furniture"] = 364;
  (*features)["shop.games"] = 365;
  (*features)["shop.garden_centre"] = 366;
  (*features)["shop.garden_furniture"] = 367;
  (*features)["shop.gas"] = 368;
  (*features)["shop.general"] = 369;
  (*features)["shop.gift"] = 370;
  (*features)["shop.glaziery"] = 371;
  (*features)["shop.greengrocer"] = 372;
  (*features)["shop.hairdresser"] = 373;
  (*features)["shop.hairdresser_supply"] = 374;
  (*features)["shop.hardware"] = 375;
  (*features)["shop.hearing_aids"] = 376;
  (*features)["shop.herbalist"] = 377;
  (*features)["shop.hifi"] = 378;
  (*features)["shop.houseware"] = 379;
  (*features)["shop.hunting"] = 380;
  (*features)["shop.ice_cream"] = 381;
  (*features)["shop.interior_decoration"] = 382;
  (*features)["shop.jewelry"] = 383;
  (*features)["shop.kiosk"] = 384;
  (*features)["shop.kitchen"] = 385;
  (*features)["shop.lamps"] = 386;
  (*features)["shop.laundry"] = 387;
  (*features)["shop.leather"] = 388;
  (*features)["shop.locksmith"] = 389;
  (*features)["shop.lottery"] = 390;
  (*features)["shop.mall"] = 391;
  (*features)["shop.massage"] = 392;
  (*features)["shop.medical_supply"] = 393;
  (*features)["shop.mobile_phone"] = 394;
  (*features)["shop.model"] = 395;
  (*features)["shop.money_lender"] = 396;
  (*features)["shop.motorcycle"] = 397;
  (*features)["shop.music"] = 398;
  (*features)["shop.musical_instrument"] = 399;
  (*features)["shop.newsagent"] = 400;
  (*features)["shop.nutrition_supplements"] = 401;
  (*features)["shop.optician"] = 402;
  (*features)["shop.organic"] = 403;
  (*features)["shop.outdoor"] = 404;
  (*features)["shop.paint"] = 405;
  (*features)["shop.pasta"] = 406;
  (*features)["shop.pastry"] = 407;
  (*features)["shop.pawnbroker"] = 408;
  (*features)["shop.perfumery"] = 409;
  (*features)["shop.pet"] = 410;
  (*features)["shop.photo"] = 411;
  (*features)["shop.pyrotechnics"] = 412;
  (*features)["shop.radiotechnics"] = 413;
  (*features)["shop.religion"] = 414;
  (*features)["shop.scuba_diving"] = 415;
  (*features)["shop.seafood"] = 416;
  (*features)["shop.second_hand"] = 417;
  (*features)["shop.security"] = 418;
  (*features)["shop.shoes"] = 419;
  (*features)["shop.spices"] = 420;
  (*features)["shop.sports"] = 421;
  (*features)["shop.stationery"] = 422;
  (*features)["shop.supermarket"] = 423;
  (*features)["shop.swimming_pool"] = 424;
  (*features)["shop.tailor"] = 425;
  (*features)["shop.tattoo"] = 426;
  (*features)["shop.tea"] = 427;
  (*features)["shop.ticket"] = 428;
  (*features)["shop.tiles"] = 429;
  (*features)["shop.tobacco"] = 430;
  (*features)["shop.toys"] = 431;
  (*features)["shop.trade"] = 432;
  (*features)["shop.travel_agency"] = 433;
  (*features)["shop.trophy"] = 434;
  (*features)["shop.tyres"] = 435;
  (*features)["shop.vacant"] = 436;
  (*features)["shop.vacuum_cleaner"] = 437;
  (*features)["shop.variety_store"] = 438;
  (*features)["shop.video"] = 439;
  (*features)["shop.video_games"] = 440;
  (*features)["shop.watches"] = 441;
  (*features)["shop.weapons"] = 442;
  (*features)["shop.window_blind"] = 443;
  (*features)["shop.wine"] = 444;
  (*features)["shop"] = 445;
  (*features)["sport.diving"] = 446;
  (*features)["sport.fencing"] = 447;
  (*features)["sport.field_hockey"] = 448;
  (*features)["sport.football"] = 449;
  (*features)["sport.free_flying"] = 450;
  (*features)["sport.handball"] = 451;
  (*features)["sport.hockey"] = 452;
  (*features)["sport.parachuting"] = 453;
  (*features)["sport.paragliding"] = 454;
  (*features)["sport.pelota"] = 455;
  (*features)["sport.racquet"] = 456;
  (*features)["sport.rc_car"] = 457;
  (*features)["sport.roller_skating"] = 458;
  (*features)["sport.rowing"] = 459;
  (*features)["sport.rugby_league"] = 460;
  (*features)["sport.rugby_union"] = 461;
  (*features)["sport.running"] = 462;
  (*features)["sport.safety_training"] = 463;
  (*features)["sport.shooting"] = 464;
  (*features)["sport.skateboard"] = 465;
  (*features)["sport.skating"] = 466;
  (*features)["sport.skiing"] = 467;
  (*features)["sport.soccer"] = 468;
  (*features)["sport.sumo"] = 469;
  (*features)["sport.surfing"] = 470;
  (*features)["sport.swimming"] = 471;
  (*features)["sport.table_soccer"] = 472;
  (*features)["sport.table_tennis"] = 473;
  (*features)["sport.tennis"] = 474;
  (*features)["sport.toboggan"] = 475;
  (*features)["sport.volleyball"] = 476;
  (*features)["sport.water_polo"] = 477;
  (*features)["sport.water_ski"] = 478;
  (*features)["sport"] = 479;
  (*features)["waterway.boatyard"] = 480;
  (*features)["waterway.canal"] = 481;
  (*features)["waterway.dam"] = 482;
  (*features)["waterway.ditch"] = 483;
  (*features)["waterway.dock"] = 484;
  (*features)["waterway.drain"] = 485;
  (*features)["waterway.drystream"] = 486;
  (*features)["waterway.fairway"] = 487;
  (*features)["waterway.fuel"] = 488;
  (*features)["waterway.lock_gate"] = 489;
  (*features)["waterway.river"] = 490;
  (*features)["waterway.riverbank"] = 491;
  (*features)["waterway.stream"] = 492;
  (*features)["waterway.turning_point"] = 493;
  (*features)["waterway.wadi"] = 494;
  (*features)["waterway.waterfall"] = 495;
  (*features)["waterway.water_point"] = 496;
  (*features)["waterway.weir"] = 497;
  (*features)["waterway"] = 498;
};
};
#endif
/*
Copyright (c) 2017 James Halliday

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef O5MDECODER_H
#define O5MDECODER_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

namespace o5mdecoder {
  typedef unsigned char TYPE;
  const TYPE NODE = 0x10;
  const TYPE WAY = 0x11;
  const TYPE REL = 0x12;
  const uint32_t MAX_TABLE_SIZE = 15000;
  enum _STATE {
    _BEGIN = 1,
    _TYPE = 2,
    _LEN = 3,
    _DATA = 4,
    _END = 5
  };
  size_t signedDelta (int64_t *d, size_t len, char *data) {
    size_t i;
    unsigned char b, m = 0x40;
    int64_t npow = data[0]%2 ? -1 : 1;
    for (i = 0; i < len; i++) {
      b = data[i] >> (i == 0 ? 1 : 0);
      *d += (b % m) * npow;
      if (b < 0x80) break;
      npow *= m;
      m = 0x80;
    }
    if (npow < 0) *d -= 1;
    return i+1;
  }
  size_t signedDelta (uint64_t *d, size_t len, char *data) {
    return signedDelta((int64_t*)d, len, data);
  }
  size_t xunsigned (uint64_t *d, size_t len, char *data) {
    size_t i;
    unsigned char b;
    int64_t npow = 1;
    for (i = 0; i < len; i++) {
      b = data[i];
      *d += (b & 0x7f) * npow;
      if (b < 0x80) break;
      npow *= 0x80;
    }
    return i+1;
  }
  size_t xunsigned (int64_t *d, size_t len, char *data) {
    return xunsigned((uint64_t*)d, len, data);
  }
  struct Member {
    TYPE type;
    uint64_t ref;
    char *role;
  };
  class Doc {
    public:
    TYPE type;
    uint64_t id;
    uint64_t version;
    int64_t timestamp;
    uint64_t changeset;
    uint64_t uid;
    size_t _taglen,_tagpos;
    char *user, *_err, *_tags, *_table;
    size_t *_tablesize, *_tablepos;
    Doc () {
      id = 0;
      version = 0;
      timestamp = 0;
      changeset = 0;
      uid = 0;
      user = NULL;
      _table = NULL;
      _tablesize = NULL;
      _tablepos = NULL;
    }
    bool getTag (char **key, char **value) {
      size_t begin, end;
      uint64_t ntable;
      if (_tagpos >= _taglen) return false;
      if (*(_tags+_tagpos) == 0) {
        begin = ++_tagpos;
        *key = _tags+_tagpos;
        for (_tagpos++;*(_tags+_tagpos) != 0 && _tagpos < _taglen; _tagpos++);
        _tagpos++;
        *value = _tags+_tagpos;
        for (;*(_tags+_tagpos) != 0 && _tagpos < _taglen; _tagpos++);
        end = ++_tagpos;
        memcpy(_table+256*(*_tablepos), _tags+begin, end-begin);
        *_tablepos = ((*_tablepos)+1)%MAX_TABLE_SIZE;
        *_tablesize = fminl((*_tablesize)+1, MAX_TABLE_SIZE);
        return true;
      } else {
        ntable = 0;
        _tagpos += xunsigned(&ntable, _taglen-_tagpos, _tags+_tagpos);
        if (ntable > *_tablesize) {
          sprintf(_err, "table number greater than table size: %u > %u",
            ntable, *_tablesize);
          throw _err;
        }
        *key = _table+256*((*_tablepos)-ntable);
        for (begin = 0; begin < 256 && *(*key+begin) != 0; begin++);
        *value = begin+*key+1;
        return true;
      }
      return false;
    }
  };
  class Node : public Doc {
    public:
    double lat;
    double lon;
    int64_t ulat;
    int64_t ulon;
    Node () {
      lon = 0;
      lat = 0;
      ulon = 0;
      ulat = 0;
    }
  };
  class Way : public Doc {
    public:
    size_t _reflen, _refpos;
    uint64_t _ref;
    char *_refbuf;
    Way () {
      _ref = 0;
    }
    bool getRef (uint64_t *ref) {
      if (_refpos >= _reflen) return false;
      _refpos += signedDelta(&_ref, _reflen-_refpos, _refbuf+_refpos);
      *ref = _ref;
      return true;
    }
  };
  class Rel : public Doc {
    public:
    size_t _memlen, _mempos;
    uint64_t _ref;
    char *_membuf;
    bool getMember (Member *member) {
      uint64_t ntable;
      size_t begin;
      if (_mempos >= _memlen) return false;
      _mempos += signedDelta(&_ref, _memlen-_mempos, _membuf+_mempos);
      member->ref = _ref;
      if (*(_membuf+_mempos) == 0) {
        _mempos++;
        begin = _mempos;
        member->type = ((unsigned char) *(_membuf+_mempos)) - 0x20;
        _mempos++;
        member->role = _membuf+_mempos;
        for (; _mempos < _memlen && *(_membuf+_mempos) != 0; _mempos++);
        _mempos++;
        memcpy(_table+(*_tablepos)*256,_membuf+begin,_mempos-begin);
        *_tablesize = fminl((*_tablesize)+1,MAX_TABLE_SIZE);
        *_tablepos = ((*_tablepos)+1)%MAX_TABLE_SIZE;
      } else {
        ntable = 0;
        _mempos += xunsigned(&ntable, _memlen-_mempos, _membuf+_mempos);
        if (ntable > *_tablesize) {
          sprintf(_err, "table number greater than table size: %u > %u",
            ntable, *_tablesize);
          throw _err;
        }
        begin = 256*((*_tablepos)-ntable);
        member->type = (unsigned char) *(_table+begin) - 0x20;
        member->role = _table+begin+1;
      }
      return true;
    }
  };
  class Decoder {
    public:
    char *buffer, *docbuf, *table, *_key, *_value;
    size_t length, docbuflen, pos, tablesize, tablepos, _ref;
    size_t doclen, docpow, docsize;
    char _err[256];
    Member _member;
    Node *node;
    Node _node;
    Way *way;
    Way _way;
    Rel *rel;
    Rel _rel;
    Node *_prevNode;
    Way *_prevWay;
    Rel *_prevRel;
    Doc *_prevDoc;
    TYPE type;

    _STATE _state;
    Decoder (char *dbuf, size_t buflen, char *stable) {
      _state = _BEGIN;
      table = stable;
      tablesize = 0;
      tablepos = 0;
      buffer = NULL;
      pos = 0;
      docbuf = dbuf;
      docbuflen = buflen;
      length = 0;
      docpow = 1;
      doclen = 0;
      docsize = 0;
      node = NULL;
      way = NULL;
      rel = NULL;
      _prevDoc = NULL;
      _prevNode = NULL;
      _prevWay = NULL;
      _prevRel = NULL;
      _node._table = table;
      _node._tablesize = &tablesize;
      _node._tablepos = &tablepos;
      _node._err = _err;
      _way._table = table;
      _way._tablesize = &tablesize;
      _way._tablepos = &tablepos;
      _way._err = _err;
      _rel._table = table;
      _rel._tablesize = &tablesize;
      _rel._tablepos = &tablepos;
      _rel._err = _err;
    }
    void write (char *data, size_t len) {
      buffer = data;
      length = len;
      pos = 0;
    }
    bool read () {
      node = NULL;
      way = NULL;
      rel = NULL;
      if (_prevDoc) while (_prevDoc->getTag(&_key,&_value));
      if (_prevWay) while (_prevWay->getRef(&_ref));
      if (_prevRel) while (_prevRel->getMember(&_member));

      size_t j;
      for (; pos < length; pos++) {
        unsigned char b = buffer[pos];
        if (_state == _BEGIN && b != 0xff) {
          sprintf(_err, "first byte in frame, expected 0xff, got 0x%x", b);
          throw _err;
        } else if (_state == _BEGIN) {
          _state = _TYPE;
        } else if (_state == _TYPE && b == 0xff) { // reset
          _state = _TYPE;
          _prevDoc = NULL;
          _prevNode = NULL;
          _prevWay = NULL;
          _prevRel = NULL;
        } else if (_state == _TYPE) {
          _state = _LEN;
          type = b;
        } else if (_state == _LEN) {
          doclen += (b & 0x7f) * docpow;
          docpow *= 0x80;
          if (b < 0x80) {
            _state = _DATA;
          }
        } else if (_state == _DATA) {
          j = fminl(length, pos + doclen - docsize);
          if (docsize+j-pos >= docbuflen) {
            sprintf(_err, "Buffer space exceeded. Try using a larger buffer.");
            throw _err;
          }
          memcpy(docbuf+docsize, buffer+pos, j-pos);
          docsize += j - pos;
          pos = j;
          if (docsize == doclen) {
            if (type == NODE) _parseNode(doclen, docbuf);
            else if (type == WAY) _parseWay(doclen, docbuf);
            else if (type == REL) _parseRel(doclen, docbuf);
            _state = _TYPE;
            doclen = 0;
            docpow = 1;
            docsize = 0;
            return true;
          }
        } else if (_state == _END) {
          // ...
        }
      }
      return false;
    }
    size_t _parseDoc (Doc *doc, size_t len, char *buf) {
      size_t pos = 0, begin = 0;
      int64_t ntable;
      if (_prevDoc) {
        doc->id = _prevDoc->id;
        doc->timestamp = _prevDoc->timestamp;
        doc->changeset = _prevDoc->changeset;
      } else {
        doc->id = 0;
        doc->version = 0;
        doc->timestamp = 0;
        doc->changeset = 0;
      }
      doc->version = 0;
      doc->uid = 0;
      doc->user = NULL;
      pos += signedDelta(&(doc->id), len-pos, buf+pos);
      if (buf[pos] == 0x00) { // no version
        doc->version = 0;
        doc->timestamp = 0;
        doc->changeset = 0;
        pos++;
      } else {
        pos += xunsigned(&(doc->version), len-pos, buf+pos);
        pos += signedDelta(&(doc->timestamp), len-pos, buf+pos);
        if (doc->timestamp == 0) {
          doc->changeset = 0;
        } else {
          pos += signedDelta(&(doc->changeset), len-pos, buf+pos);
          if (*(buf+pos) == 0) { // inline string
            begin = ++pos;
            pos += xunsigned(&(doc->uid), len-pos, buf+pos);
            if (*(buf+pos) != 0) {
              sprintf(_err, "expected 0x00 after uid, got 0x%x", *(buf+pos));
              throw _err;
            }
            for (; pos < len && *(buf+pos) != 0; pos++);
            pos++;
            doc->user = buf+pos;
            for (; pos < len && *(buf+pos) != 0; pos++);
            pos++;
            memcpy(table+tablepos*256,buf+begin,pos-begin);
            tablesize = fminl(tablesize+1,MAX_TABLE_SIZE);
            tablepos = (tablepos+1)%MAX_TABLE_SIZE;
          } else { // string table lookup
            ntable = 0;
            pos += xunsigned(&ntable, len-pos, buf+pos);
            if (ntable > tablesize) {
              sprintf(_err, "table number greater than table size: %u > %u",
                ntable, tablesize);
              throw _err;
            }
            begin = xunsigned(&(doc->uid), 256, table+256*(tablepos-ntable));
            doc->user = table+256*(tablepos-ntable)+begin+1;
          }
        }
      }
      return pos;
    }
    size_t _parseTags (Doc *doc, size_t len, char *buf) {
      doc->_tags = buf;
      doc->_taglen = len;
      doc->_tagpos = 0;
      return len;
    }
    void _parseNode (size_t len, char *buf) {
      node = &_node;
      size_t pos = _parseDoc(node, len, buf);
      int64_t ulat = _prevNode ? _prevNode->ulat : 0;
      int64_t ulon = _prevNode ? _prevNode->ulon : 0;
      pos += signedDelta(&ulon, len-pos, buf+pos); // lon
      pos += signedDelta(&ulat, len-pos, buf+pos); // lat
      node->ulon = ulon;
      node->ulat = ulat;
      node->lon = ((double) ulon) / 1e7;
      node->lat = ((double) ulat) / 1e7;
      pos += _parseTags(node, len-pos, buf+pos);
      _prevNode = node;
      _prevDoc = node;
    }
    void _parseWay (size_t len, char *buf) {
      way = &_way;
      size_t pos = _parseDoc(way, len, buf);
      way->_reflen = 0;
      way->_refpos = 0;
      way->_ref = _prevWay ? _prevWay->_ref : 0;
      pos += xunsigned(&(way->_reflen), len-pos, buf+pos);
      way->_refbuf = buf+pos;
      pos += way->_reflen;
      pos += _parseTags(way, len-pos, buf+pos);
      _prevWay = way;
      _prevDoc = way;
    }
    void _parseRel (size_t len, char *buf) {
      rel = &_rel;
      size_t pos = _parseDoc(rel, len, buf);
      rel->_memlen = 0;
      rel->_mempos = 0;
      rel->_ref = 0;
      pos += xunsigned(&(rel->_memlen), len-pos, buf+pos);
      rel->_membuf = buf+pos;
      pos += rel->_memlen;
      pos += _parseTags(rel, len-pos, buf+pos);
      _prevRel = rel;
      _prevDoc = rel;
    }
  };
}

#endif
/*
ISC License

Copyright (c) 2015, Mapbox

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/
#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <memory>
#include <vector>
#include <tuple>
#include <cstddef>

namespace mapbox {

namespace util {

template <std::size_t I, typename T> struct nth {
    inline static typename std::tuple_element<I, T>::type
    get(const T& t) { return std::get<I>(t); };
};

}

namespace detail {

template <typename N = uint32_t>
class Earcut {
public:
    std::vector<N> indices;
    N vertices = 0;

    template <typename Polygon>
    void operator()(const Polygon& points);

private:
    struct Node {
        Node(N index, double x_, double y_) : i(index), x(x_), y(y_) {}
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        Node(Node&&) = delete;
        Node& operator=(Node&&) = delete;

        const N i;
        const double x;
        const double y;

        // previous and next vertice nodes in a polygon ring
        Node* prev = nullptr;
        Node* next = nullptr;

        // z-order curve value
        int32_t z = 0;

        // previous and next nodes in z-order
        Node* prevZ = nullptr;
        Node* nextZ = nullptr;

        // indicates whether this is a steiner point
        bool steiner = false;
    };

    template <typename Ring> Node* linkedList(const Ring& points, const bool clockwise);
    Node* filterPoints(Node* start, Node* end = nullptr);
    void earcutLinked(Node* ear, int pass = 0);
    bool isEar(Node* ear);
    bool isEarHashed(Node* ear);
    Node* cureLocalIntersections(Node* start);
    void splitEarcut(Node* start);
    template <typename Polygon> Node* eliminateHoles(const Polygon& points, Node* outerNode);
    void eliminateHole(Node* hole, Node* outerNode);
    Node* findHoleBridge(Node* hole, Node* outerNode);
    void indexCurve(Node* start);
    Node* sortLinked(Node* list);
    int32_t zOrder(const double x_, const double y_);
    Node* getLeftmost(Node* start);
    bool pointInTriangle(double ax, double ay, double bx, double by, double cx, double cy, double px, double py) const;
    bool isValidDiagonal(Node* a, Node* b);
    double area(const Node* p, const Node* q, const Node* r) const;
    bool equals(const Node* p1, const Node* p2);
    bool intersects(const Node* p1, const Node* q1, const Node* p2, const Node* q2);
    bool intersectsPolygon(const Node* a, const Node* b);
    bool locallyInside(const Node* a, const Node* b);
    bool middleInside(const Node* a, const Node* b);
    Node* splitPolygon(Node* a, Node* b);
    template <typename Point> Node* insertNode(N i, const Point& p, Node* last);
    void removeNode(Node* p);

    bool hashing;
    double minX, maxX;
    double minY, maxY;
    double size;

    template <typename T, typename Alloc = std::allocator<T>>
    class ObjectPool {
    public:
        ObjectPool() { }
        ObjectPool(std::size_t blockSize_) {
            reset(blockSize_);
        }
        ~ObjectPool() {
            clear();
        }
        template <typename... Args>
        T* construct(Args&&... args) {
            if (currentIndex >= blockSize) {
                currentBlock = alloc.allocate(blockSize);
                allocations.emplace_back(currentBlock);
                currentIndex = 0;
            }
            T* object = &currentBlock[currentIndex++];
            alloc.construct(object, std::forward<Args>(args)...);
            return object;
        }
        void reset(std::size_t newBlockSize) {
            for (auto allocation : allocations) alloc.deallocate(allocation, blockSize);
            allocations.clear();
            blockSize = std::max<std::size_t>(1, newBlockSize);
            currentBlock = nullptr;
            currentIndex = blockSize;
        }
        void clear() { reset(blockSize); }
    private:
        T* currentBlock = nullptr;
        std::size_t currentIndex = 1;
        std::size_t blockSize = 1;
        std::vector<T*> allocations;
        Alloc alloc;
    };
    ObjectPool<Node> nodes;
};

template <typename N> template <typename Polygon>
void Earcut<N>::operator()(const Polygon& points) {
    // reset
    indices.clear();
    vertices = 0;

    if (points.empty()) return;

    double x;
    double y;
    size = 0;
    int threshold = 80;
    std::size_t len = 0;

    for (size_t i = 0; threshold >= 0 && i < points.size(); i++) {
        threshold -= static_cast<int>(points[i].size());
        len += points[i].size();
    }

    //estimate size of nodes and indices
    nodes.reset(len * 3 / 2);
    indices.reserve(len + points[0].size());

    Node* outerNode = linkedList(points[0], true);
    if (!outerNode) return;

    if (points.size() > 1) outerNode = eliminateHoles(points, outerNode);

    // if the shape is not too simple, we'll use z-order curve hash later; calculate polygon bbox
    hashing = threshold < 0;
    if (hashing) {
        Node* p = outerNode->next;
        minX = maxX = p->x;
        minY = maxY = p->y;
        do {
            x = p->x;
            y = p->y;
            minX = (std::min)(minX, x);
            minY = (std::min)(minY, y);
            maxX = (std::max)(maxX, x);
            maxY = (std::max)(maxY, y);
            p = p->next;
        } while (p != outerNode);

        // minX, minY and size are later used to transform coords into integers for z-order calculation
        size = (std::max)(maxX - minX, maxY - minY);
    }

    earcutLinked(outerNode);

    nodes.clear();
}

// create a circular doubly linked list from polygon points in the specified winding order
template <typename N> template <typename Ring>
typename Earcut<N>::Node*
Earcut<N>::linkedList(const Ring& points, const bool clockwise) {
    using Point = typename Ring::value_type;
    double sum = 0;
    const int len = static_cast<int>(points.size());
    int i, j;
    Point p1, p2;
    Node* last = nullptr;

    // calculate original winding order of a polygon ring
    for (i = 0, j = len - 1; i < len; j = i++) {
        p1 = points[i];
        p2 = points[j];
        const double p20 = util::nth<0, Point>::get(p2);
        const double p10 = util::nth<0, Point>::get(p1);
        const double p11 = util::nth<1, Point>::get(p1);
        const double p21 = util::nth<1, Point>::get(p2);
        sum += (p20 - p10) * (p11 + p21);
    }

    // link points into circular doubly-linked list in the specified winding order
    if (clockwise == (sum > 0)) {
        for (i = 0; i < len; i++) last = insertNode(vertices + i, points[i], last);
    } else {
        for (i = len - 1; i >= 0; i--) last = insertNode(vertices + i, points[i], last);
    }

    if (last && equals(last, last->next)) {
        removeNode(last);
        last = last->next;
    }

    vertices += len;

    return last;
}

// eliminate colinear or duplicate points
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::filterPoints(Node* start, Node* end) {
    if (!end) end = start;

    Node* p = start;
    bool again;
    do {
        again = false;

        if (!p->steiner && (equals(p, p->next) || area(p->prev, p, p->next) == 0)) {
            removeNode(p);
            p = end = p->prev;

            if (p == p->next) return nullptr;
            again = true;

        } else {
            p = p->next;
        }
    } while (again || p != end);

    return end;
}

// main ear slicing loop which triangulates a polygon (given as a linked list)
template <typename N>
void Earcut<N>::earcutLinked(Node* ear, int pass) {
    if (!ear) return;

    // interlink polygon nodes in z-order
    if (!pass && hashing) indexCurve(ear);

    Node* stop = ear;
    Node* prev;
    Node* next;

    int iterations = 0;

    // iterate through ears, slicing them one by one
    while (ear->prev != ear->next) {
        iterations++;
        prev = ear->prev;
        next = ear->next;

        if (hashing ? isEarHashed(ear) : isEar(ear)) {
            // cut off the triangle
            indices.emplace_back(prev->i);
            indices.emplace_back(ear->i);
            indices.emplace_back(next->i);

            removeNode(ear);

            // skipping the next vertice leads to less sliver triangles
            ear = next->next;
            stop = next->next;

            continue;
        }

        ear = next;

        // if we looped through the whole remaining polygon and can't find any more ears
        if (ear == stop) {
            // try filtering points and slicing again
            if (!pass) earcutLinked(filterPoints(ear), 1);

            // if this didn't work, try curing all small self-intersections locally
            else if (pass == 1) {
                ear = cureLocalIntersections(ear);
                earcutLinked(ear, 2);

            // as a last resort, try splitting the remaining polygon into two
            } else if (pass == 2) splitEarcut(ear);

            break;
        }
    }
}

// check whether a polygon node forms a valid ear with adjacent nodes
template <typename N>
bool Earcut<N>::isEar(Node* ear) {
    const Node* a = ear->prev;
    const Node* b = ear;
    const Node* c = ear->next;

    if (area(a, b, c) >= 0) return false; // reflex, can't be an ear

    // now make sure we don't have other points inside the potential ear
    Node* p = ear->next->next;

    while (p != ear->prev) {
        if (pointInTriangle(a->x, a->y, b->x, b->y, c->x, c->y, p->x, p->y) &&
            area(p->prev, p, p->next) >= 0) return false;
        p = p->next;
    }

    return true;
}

template <typename N>
bool Earcut<N>::isEarHashed(Node* ear) {
    const Node* a = ear->prev;
    const Node* b = ear;
    const Node* c = ear->next;

    if (area(a, b, c) >= 0) return false; // reflex, can't be an ear

    // triangle bbox; min & max are calculated like this for speed
    const double minTX = (std::min)(a->x, (std::min)(b->x, c->x));
    const double minTY = (std::min)(a->y, (std::min)(b->y, c->y));
    const double maxTX = (std::max)(a->x, (std::max)(b->x, c->x));
    const double maxTY = (std::max)(a->y, (std::max)(b->y, c->y));

    // z-order range for the current triangle bbox;
    const int32_t minZ = zOrder(minTX, minTY);
    const int32_t maxZ = zOrder(maxTX, maxTY);

    // first look for points inside the triangle in increasing z-order
    Node* p = ear->nextZ;

    while (p && p->z <= maxZ) {
        if (p != ear->prev && p != ear->next &&
            pointInTriangle(a->x, a->y, b->x, b->y, c->x, c->y, p->x, p->y) &&
            area(p->prev, p, p->next) >= 0) return false;
        p = p->nextZ;
    }

    // then look for points in decreasing z-order
    p = ear->prevZ;

    while (p && p->z >= minZ) {
        if (p != ear->prev && p != ear->next &&
            pointInTriangle(a->x, a->y, b->x, b->y, c->x, c->y, p->x, p->y) &&
            area(p->prev, p, p->next) >= 0) return false;
        p = p->prevZ;
    }

    return true;
}

// go through all polygon nodes and cure small local self-intersections
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::cureLocalIntersections(Node* start) {
    Node* p = start;
    do {
        Node* a = p->prev;
        Node* b = p->next->next;

        // a self-intersection where edge (v[i-1],v[i]) intersects (v[i+1],v[i+2])
        if (!equals(a, b) && intersects(a, p, p->next, b) && locallyInside(a, b) && locallyInside(b, a)) {
            indices.emplace_back(a->i);
            indices.emplace_back(p->i);
            indices.emplace_back(b->i);

            // remove two nodes involved
            removeNode(p);
            removeNode(p->next);

            p = start = b;
        }
        p = p->next;
    } while (p != start);

    return p;
}

// try splitting polygon into two and triangulate them independently
template <typename N>
void Earcut<N>::splitEarcut(Node* start) {
    // look for a valid diagonal that divides the polygon into two
    Node* a = start;
    do {
        Node* b = a->next->next;
        while (b != a->prev) {
            if (a->i != b->i && isValidDiagonal(a, b)) {
                // split the polygon in two by the diagonal
                Node* c = splitPolygon(a, b);

                // filter colinear points around the cuts
                a = filterPoints(a, a->next);
                c = filterPoints(c, c->next);

                // run earcut on each half
                earcutLinked(a);
                earcutLinked(c);
                return;
            }
            b = b->next;
        }
        a = a->next;
    } while (a != start);
}

// link every hole into the outer loop, producing a single-ring polygon without holes
template <typename N> template <typename Polygon>
typename Earcut<N>::Node*
Earcut<N>::eliminateHoles(const Polygon& points, Node* outerNode) {
    const size_t len = points.size();

    std::vector<Node*> queue;
    for (size_t i = 1; i < len; i++) {
        Node* list = linkedList(points[i], false);
        if (list) {
            if (list == list->next) list->steiner = true;
            queue.push_back(getLeftmost(list));
        }
    }
    std::sort(queue.begin(), queue.end(), [this](const Node* a, const Node* b) {
        return a->x < b->x;
    });

    // process holes from left to right
    for (size_t i = 0; i < queue.size(); i++) {
        eliminateHole(queue[i], outerNode);
        outerNode = filterPoints(outerNode, outerNode->next);
    }

    return outerNode;
}

// find a bridge between vertices that connects hole with an outer ring and and link it
template <typename N>
void Earcut<N>::eliminateHole(Node* hole, Node* outerNode) {
    outerNode = findHoleBridge(hole, outerNode);
    if (outerNode) {
        Node* b = splitPolygon(outerNode, hole);
        filterPoints(b, b->next);
    }
}

// David Eberly's algorithm for finding a bridge between hole and outer polygon
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::findHoleBridge(Node* hole, Node* outerNode) {
    Node* p = outerNode;
    double hx = hole->x;
    double hy = hole->y;
    double qx = -std::numeric_limits<double>::infinity();
    Node* m = nullptr;

    // find a segment intersected by a ray from the hole's leftmost Vertex to the left;
    // segment's endpoint with lesser x will be potential connection Vertex
    do {
        if (hy <= p->y && hy >= p->next->y && p->next->y != p->y) {
          double x = p->x + (hy - p->y) * (p->next->x - p->x) / (p->next->y - p->y);
          if (x <= hx && x > qx) {
            qx = x;
            if (x == hx) {
                if (hy == p->y) return p;
                if (hy == p->next->y) return p->next;
            }
            m = p->x < p->next->x ? p : p->next;
          }
        }
        p = p->next;
    } while (p != outerNode);

    if (!m) return 0;

    if (hx == qx) return m->prev;

    // look for points inside the triangle of hole Vertex, segment intersection and endpoint;
    // if there are no points found, we have a valid connection;
    // otherwise choose the Vertex of the minimum angle with the ray as connection Vertex

    const Node* stop = m;
    double tanMin = std::numeric_limits<double>::infinity();
    double tanCur = 0;

    p = m->next;
    double mx = m->x;
    double my = m->y;

    while (p != stop) {
        if (hx >= p->x && p->x >= mx && hx != p->x &&
            pointInTriangle(hy < my ? hx : qx, hy, mx, my, hy < my ? qx : hx, hy, p->x, p->y)) {

            tanCur = std::abs(hy - p->y) / (hx - p->x); // tangential

            if ((tanCur < tanMin || (tanCur == tanMin && p->x > m->x)) && locallyInside(p, hole)) {
                m = p;
                tanMin = tanCur;
            }
        }

        p = p->next;
    }

    return m;
}

// interlink polygon nodes in z-order
template <typename N>
void Earcut<N>::indexCurve(Node* start) {
    assert(start);
    Node* p = start;

    do {
        p->z = p->z ? p->z : zOrder(p->x, p->y);
        p->prevZ = p->prev;
        p->nextZ = p->next;
        p = p->next;
    } while (p != start);

    p->prevZ->nextZ = nullptr;
    p->prevZ = nullptr;

    sortLinked(p);
}

// Simon Tatham's linked list merge sort algorithm
// http://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::sortLinked(Node* list) {
    assert(list);
    Node* p;
    Node* q;
    Node* e;
    Node* tail;
    int i, numMerges, pSize, qSize;
    int inSize = 1;

    while (true) {
        p = list;
        list = nullptr;
        tail = nullptr;
        numMerges = 0;

        while (p) {
            numMerges++;
            q = p;
            pSize = 0;
            for (i = 0; i < inSize; i++) {
                pSize++;
                q = q->nextZ;
                if (!q) break;
            }

            qSize = inSize;

            while (pSize > 0 || (qSize > 0 && q)) {

                if (pSize == 0) {
                    e = q;
                    q = q->nextZ;
                    qSize--;
                } else if (qSize == 0 || !q) {
                    e = p;
                    p = p->nextZ;
                    pSize--;
                } else if (p->z <= q->z) {
                    e = p;
                    p = p->nextZ;
                    pSize--;
                } else {
                    e = q;
                    q = q->nextZ;
                    qSize--;
                }

                if (tail) tail->nextZ = e;
                else list = e;

                e->prevZ = tail;
                tail = e;
            }

            p = q;
        }

        tail->nextZ = nullptr;

        if (numMerges <= 1) return list;

        inSize *= 2;
    }
}

// z-order of a Vertex given coords and size of the data bounding box
template <typename N>
int32_t Earcut<N>::zOrder(const double x_, const double y_) {
    // coords are transformed into non-negative 15-bit integer range
    int32_t x = static_cast<int32_t>(32767.0 * (x_ - minX) / size);
    int32_t y = static_cast<int32_t>(32767.0 * (y_ - minY) / size);

    x = (x | (x << 8)) & 0x00FF00FF;
    x = (x | (x << 4)) & 0x0F0F0F0F;
    x = (x | (x << 2)) & 0x33333333;
    x = (x | (x << 1)) & 0x55555555;

    y = (y | (y << 8)) & 0x00FF00FF;
    y = (y | (y << 4)) & 0x0F0F0F0F;
    y = (y | (y << 2)) & 0x33333333;
    y = (y | (y << 1)) & 0x55555555;

    return x | (y << 1);
}

// find the leftmost node of a polygon ring
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::getLeftmost(Node* start) {
    Node* p = start;
    Node* leftmost = start;
    do {
        if (p->x < leftmost->x) leftmost = p;
        p = p->next;
    } while (p != start);

    return leftmost;
}

// check if a point lies within a convex triangle
template <typename N>
bool Earcut<N>::pointInTriangle(double ax, double ay, double bx, double by, double cx, double cy, double px, double py) const {
    return (cx - px) * (ay - py) - (ax - px) * (cy - py) >= 0 &&
           (ax - px) * (by - py) - (bx - px) * (ay - py) >= 0 &&
           (bx - px) * (cy - py) - (cx - px) * (by - py) >= 0;
}

// check if a diagonal between two polygon nodes is valid (lies in polygon interior)
template <typename N>
bool Earcut<N>::isValidDiagonal(Node* a, Node* b) {
    return a->next->i != b->i && a->prev->i != b->i && !intersectsPolygon(a, b) &&
           locallyInside(a, b) && locallyInside(b, a) && middleInside(a, b);
}

// signed area of a triangle
template <typename N>
double Earcut<N>::area(const Node* p, const Node* q, const Node* r) const {
    return (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
}

// check if two points are equal
template <typename N>
bool Earcut<N>::equals(const Node* p1, const Node* p2) {
    return p1->x == p2->x && p1->y == p2->y;
}

// check if two segments intersect
template <typename N>
bool Earcut<N>::intersects(const Node* p1, const Node* q1, const Node* p2, const Node* q2) {
    if ((equals(p1, q1) && equals(p2, q2)) ||
        (equals(p1, q2) && equals(p2, q1))) return true;
    return (area(p1, q1, p2) > 0) != (area(p1, q1, q2) > 0) &&
           (area(p2, q2, p1) > 0) != (area(p2, q2, q1) > 0);
}

// check if a polygon diagonal intersects any polygon segments
template <typename N>
bool Earcut<N>::intersectsPolygon(const Node* a, const Node* b) {
    const Node* p = a;
    do {
        if (p->i != a->i && p->next->i != a->i && p->i != b->i && p->next->i != b->i &&
                intersects(p, p->next, a, b)) return true;
        p = p->next;
    } while (p != a);

    return false;
}

// check if a polygon diagonal is locally inside the polygon
template <typename N>
bool Earcut<N>::locallyInside(const Node* a, const Node* b) {
    return area(a->prev, a, a->next) < 0 ?
        area(a, b, a->next) >= 0 && area(a, a->prev, b) >= 0 :
        area(a, b, a->prev) < 0 || area(a, a->next, b) < 0;
}

// check if the middle Vertex of a polygon diagonal is inside the polygon
template <typename N>
bool Earcut<N>::middleInside(const Node* a, const Node* b) {
    const Node* p = a;
    bool inside = false;
    double px = (a->x + b->x) / 2;
    double py = (a->y + b->y) / 2;
    do {
        if (((p->y > py) != (p->next->y > py)) && p->next->y != p->y &&
                (px < (p->next->x - p->x) * (py - p->y) / (p->next->y - p->y) + p->x))
            inside = !inside;
        p = p->next;
    } while (p != a);

    return inside;
}

// link two polygon vertices with a bridge; if the vertices belong to the same ring, it splits
// polygon into two; if one belongs to the outer ring and another to a hole, it merges it into a
// single ring
template <typename N>
typename Earcut<N>::Node*
Earcut<N>::splitPolygon(Node* a, Node* b) {
    Node* a2 = nodes.construct(a->i, a->x, a->y);
    Node* b2 = nodes.construct(b->i, b->x, b->y);
    Node* an = a->next;
    Node* bp = b->prev;

    a->next = b;
    b->prev = a;

    a2->next = an;
    an->prev = a2;

    b2->next = a2;
    a2->prev = b2;

    bp->next = b2;
    b2->prev = bp;

    return b2;
}

// create a node and util::optionally link it with previous one (in a circular doubly linked list)
template <typename N> template <typename Point>
typename Earcut<N>::Node*
Earcut<N>::insertNode(N i, const Point& pt, Node* last) {
    Node* p = nodes.construct(i, util::nth<0, Point>::get(pt), util::nth<1, Point>::get(pt));

    if (!last) {
        p->prev = p;
        p->next = p;

    } else {
        assert(last);
        p->next = last->next;
        p->prev = last;
        last->next->prev = p;
        last->next = p;
    }
    return p;
}

template <typename N>
void Earcut<N>::removeNode(Node* p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;

    if (p->prevZ) p->prevZ->nextZ = p->nextZ;
    if (p->nextZ) p->nextZ->prevZ = p->prevZ;
}
}

template <typename N = uint32_t, typename Polygon>
std::vector<N> earcut(const Polygon& poly) {
    mapbox::detail::Earcut<N> earcut;
    earcut(poly);
    return earcut.indices;
}
}
#include <endian.h>

namespace tilemesh {

const char magic[11] = "TILEMESH\n\0";
const char version[256] = "1.0.0\n\0";
static char tmp[256];
static double ptx[512];
static double pty[512];

enum STAGES {
  MAGIC_STAGE = 0,
  VERSION_STAGE = 1,
  PTLEN_STAGE = 2,
  PTDATA_STAGE = 3,
  LINELEN_STAGE = 4,
  LINEDATA_STAGE = 5,
  LINEPT_STAGE = 6,
  AREALEN_STAGE = 7,
  AREADATA_STAGE = 8,
  AREAPT_STAGE = 9,
  AREACELL_STAGE = 10,
  FINAL_STAGE = 11
};

template<class T> struct ListItem {
  T *data;
  ListItem<T> *next;
  ListItem (T *_data) {
    data = _data;
    next = NULL;
  }
};
template<class T> struct List {
  size_t length;
  ListItem<T> *first;
  ListItem<T> *last;
  List () {
    length = 0;
    first = NULL;
    last = NULL;
  }
  void push (T* p) {
    ListItem<T> *item = new ListItem<T>(p);
    if (!first) first = item;
    if (last) {
      last->next = item;
    }
    last = item;
    length++;
  }
};
struct Point {
  uint64_t id;
  uint16_t type;
  float lon, lat;
  static const size_t size = 18;
  Point (uint64_t _id, uint16_t _type, float _lon, float _lat) {
    id = _id;
    type = _type;
    lon = _lon;
    lat = _lat;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    // assumes integer byte order is the same as floating point byte order
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lon));
    pos += sizeof(float);
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lat));
    pos += sizeof(float);
    return pos;
  }
};
struct Position {
  float lon, lat;
  static const size_t size = 8;
  Position (float _lon, float _lat) {
    lon = _lon;
    lat = _lat;
  }
  bool operator==(Position &p) {
    return lon == p.lon && lat == p.lat;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lon));
    pos += sizeof(float);
    *(uint32_t*)(dst+pos) = htobe32(*((uint32_t*)&lat));
    pos += sizeof(float);
    return pos;
  }
};
struct Line {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  static const size_t size = 12;
  Line (uint64_t _id, uint16_t _type, List<Position> *poslist) {
    id = _id;
    type = _type;
    positions = poslist;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) positions->length);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Cell {
  uint16_t i;
  uint16_t j;
  uint16_t k;
  static const size_t size = 6;
  Cell (uint16_t _i, uint16_t _j, uint16_t _k) {
    i = _i;
    j = _j;
    k = _k;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint16_t*)(dst+pos) = htobe16(i);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16(j);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16(k);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Area {
  uint64_t id;
  uint16_t type;
  List<Position> *positions;
  List<Cell> *cells;
  static const size_t size = 14;
  Area (uint64_t _id, uint16_t _type,
  List<Position> *plist, List<Cell> *clist) {
    id = _id;
    type = _type;
    positions = plist;
    cells = clist;
  }
  size_t write (char *dst) {
    size_t pos = 0;
    *(uint64_t*)(dst+pos) = htobe64(id);
    pos += sizeof(uint64_t);
    *(uint16_t*)(dst+pos) = htobe16(type);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) positions->length);
    pos += sizeof(uint16_t);
    *(uint16_t*)(dst+pos) = htobe16((uint16_t) cells->length);
    pos += sizeof(uint16_t);
    return pos;
  }
};
struct Data {
  List<Point> points;
  List<Line> lines;
  List<Area> areas;
  Data () {
  }
};
void triangulate (List<Cell> *outclist, List<Position> *inplist) {
  std::vector<std::vector<std::array<float,2>>> polygon;
  std::vector<std::array<float,2>> first;
  polygon.push_back(first);
  ListItem<Position> *ipos = inplist->first;
  std::array<float,2> apt;
  while (ipos != NULL) {
    apt = { ipos->data->lon, ipos->data->lat };
    polygon[0].push_back(apt);
    ipos = ipos->next;
  }
  std::vector<uint16_t> cells = mapbox::earcut<uint16_t>(polygon);
  std::array<float,2> *pt;
  size_t len = cells.size();
  for (size_t i = 0; i < len; i+=3) {
    outclist->push(new Cell(cells[i+0], cells[i+1], cells[i+2]));
  }
}
size_t find_feature_kv (Features *features, char *key, char *value) {
  FeaturesIterator ti;
  size_t i,j;
  for (i = 0; key[i] != 0; i++) tmp[i] = key[i];
  tmp[i++] = '.';
  for (j = 0; value[j] != 0; j++) tmp[i++] = value[j];
  tmp[i++] = 0;
  ti = features->find(tmp);
  if (ti == features->end()) {
    ti = features->find(key);
    if (ti == features->end()) return 0;
    else return ti->second;
  }
  return ti->second;
}
size_t find_feature (Features *features, o5mdecoder::Doc *doc) {
  size_t ftype;
  char *key, *value;
  while (doc->getTag(&key,&value)) {
    ftype = find_feature_kv(features, key, value);
    if (ftype > 0) return ftype;
  }
  return 0;
}
struct o5m {
  char *data, *dbuf, *table;
  o5mdecoder::Decoder *decoder;
  uint64_t ref;
  std::map<uint64_t,Position*> nodes;
  std::map<uint64_t,Position*>::const_iterator ipt;
  Features features;
  Data tdata;
  Position *pos;
  Point *pt;
  Area *area;
  Line *line;
  List<Position> *poslist;
  List<Cell> *aclist;
  ListItem<Point> *ipoint;
  ListItem<Position> *ipos;
  ListItem<Cell> *icell;
  ListItem<Line> *iline;
  ListItem<Area> *iarea;

  size_t readpos, readnum;
  uint16_t readstage;
  o5m () {
    dbuf = (char*) malloc(16384);
    table = (char*) malloc(256*15000);
    decoder = new o5mdecoder::Decoder(dbuf,16384,table);
    load_features(&features);
    readpos = 0;
    readstage = 0;
  }
  void write (char *data, size_t len) {
    size_t ftype;
    decoder->write(data, len);
    while (decoder->read()) {
      if (decoder->node) {
        pt = new Point(decoder->node->id,
          find_feature(&features, decoder->node),
          decoder->node->lon, decoder->node->lat);
        tdata.points.push(pt);
        pos = new Position(decoder->node->lon, decoder->node->lat);
        nodes[decoder->node->id] = pos;
      } else if (decoder->way) {
        ftype = find_feature(&features, decoder->way);
        poslist = new List<Position>;
        while (decoder->way->getRef(&ref)) {
          ipt = nodes.find(ref);
          if (ipt == nodes.end()) continue;
          poslist->push(ipt->second);
        }
        if (poslist->length >= 2
        && poslist->first->data == poslist->last->data) { // closed, area
          aclist = new List<Cell>;
          triangulate(aclist,poslist);
          area = new Area(decoder->way->id, ftype, poslist, aclist);
          tdata.areas.push(area);
        } else { // open, line
          line = new Line(decoder->way->id, ftype, poslist);
          tdata.lines.push(line);
        }
      }
    }
  }
  bool read (char *data, size_t len, size_t *outlen) {
    size_t n, pos = 0;
    *outlen = 0;
    while (true) {
      switch (readstage) {
        case MAGIC_STAGE:
          n = strlen(magic);
          if (len-pos < n) return true;
          strncpy(data+pos, magic, n);
          *outlen = (pos += n);
          readstage = VERSION_STAGE;
          break;
        case VERSION_STAGE:
          n = strlen(version);
          if (len-pos < n) return true;
          strncpy(data+pos, version, n);
          *outlen = (pos += n);
          readstage = PTLEN_STAGE;
          break;
        case PTLEN_STAGE: // point length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.points.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = PTDATA_STAGE;
          ipoint = tdata.points.first;
          break;
        case PTDATA_STAGE: // point data
          if (ipoint == NULL) {
            readstage = LINELEN_STAGE;
            continue;
          }
          if (len-pos < Point::size) return true;
          *outlen = (pos += ipoint->data->write(data+pos));
          ipoint = ipoint->next;
          break;
        case LINELEN_STAGE: // line length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.lines.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = LINEDATA_STAGE;
          iline = tdata.lines.first;
          break;
        case LINEDATA_STAGE: // line data
          if (iline == NULL) {
            readstage = AREALEN_STAGE;
            continue;
          }
          if (len-pos < Line::size) return true;
          *outlen = (pos += iline->data->write(data+pos));
          ipos = iline->data->positions->first;
          readstage = LINEPT_STAGE;
          break;
        case LINEPT_STAGE: // line point
          if (ipos == NULL) {
            readstage = LINEDATA_STAGE;
            iline = iline->next;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        case AREALEN_STAGE: // area length
          if (len-pos < sizeof(uint32_t)) return true;
          *(uint32_t*)(data+pos) = htobe32((uint32_t) tdata.areas.length);
          *outlen = (pos += sizeof(uint32_t));
          readstage = AREADATA_STAGE;
          iarea = tdata.areas.first;
          break;
        case AREADATA_STAGE: // area data
          if (iarea == NULL) {
            readstage = FINAL_STAGE;
            continue;
          }
          if (len-pos < Area::size) return true;
          *outlen = (pos += iarea->data->write(data+pos));
          ipos = iarea->data->positions->first;
          readstage++;
          break;
        case AREAPT_STAGE: // area point
          if (ipos == NULL) {
            readstage = AREACELL_STAGE;
            icell = iarea->data->cells->first;
            continue;
          }
          if (len-pos < Position::size) return true;
          *outlen = (pos += ipos->data->write(data+pos));
          ipos = ipos->next;
          break;
        case AREACELL_STAGE: // area cell
          if (icell == NULL) {
            readstage = AREADATA_STAGE;
            iarea = iarea->next;
            continue;
          }
          if (len-pos < Cell::size) return true;
          *outlen = (pos += icell->data->write(data+pos));
          icell = icell->next;
          break;
        case FINAL_STAGE:
        default:
          return false;
          break;
      }
    }
  }
};
};
#endif
