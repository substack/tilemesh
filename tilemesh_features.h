#ifndef TILEMESH_FEATURES_H
#define TILEMESH_FEATURES_H
#include <map>
#include <stdint.h>

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
