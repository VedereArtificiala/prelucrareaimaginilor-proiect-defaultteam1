#include "Tools.h"

QVector<QRgb> Tools::grayLUT =
{
	4278190080, 4278255873, 4278321666, 4278387459, 4278453252, 4278519045, 4278584838, 4278650631,
	4278716424, 4278782217, 4278848010, 4278913803, 4278979596, 4279045389, 4279111182, 4279176975,
	4279242768, 4279308561, 4279374354, 4279440147, 4279505940, 4279571733, 4279637526, 4279703319,
	4279769112, 4279834905, 4279900698, 4279966491, 4280032284, 4280098077, 4280163870, 4280229663,
	4280295456, 4280361249, 4280427042, 4280492835, 4280558628, 4280624421, 4280690214, 4280756007,
	4280821800, 4280887593, 4280953386, 4281019179, 4281084972, 4281150765, 4281216558, 4281282351,
	4281348144, 4281413937, 4281479730, 4281545523, 4281611316, 4281677109, 4281742902, 4281808695,
	4281874488, 4281940281, 4282006074, 4282071867, 4282137660, 4282203453, 4282269246, 4282335039,
	4282400832, 4282466625, 4282532418, 4282598211, 4282664004, 4282729797, 4282795590, 4282861383,
	4282927176, 4282992969, 4283058762, 4283124555, 4283190348, 4283256141, 4283321934, 4283387727,
	4283453520, 4283519313, 4283585106, 4283650899, 4283716692, 4283782485, 4283848278, 4283914071,
	4283979864, 4284045657, 4284111450, 4284177243, 4284243036, 4284308829, 4284374622, 4284440415,
	4284506208, 4284572001, 4284637794, 4284703587, 4284769380, 4284835173, 4284900966, 4284966759,
	4285032552, 4285098345, 4285164138, 4285229931, 4285295724, 4285361517, 4285427310, 4285493103,
	4285558896, 4285624689, 4285690482, 4285756275, 4285822068, 4285887861, 4285953654, 4286019447,
	4286085240, 4286151033, 4286216826, 4286282619, 4286348412, 4286414205, 4286479998, 4286545791,
	4286611584, 4286677377, 4286743170, 4286808963, 4286874756, 4286940549, 4287006342, 4287072135,
	4287137928, 4287203721, 4287269514, 4287335307, 4287401100, 4287466893, 4287532686, 4287598479,
	4287664272, 4287730065, 4287795858, 4287861651, 4287927444, 4287993237, 4288059030, 4288124823,
	4288190616, 4288256409, 4288322202, 4288387995, 4288453788, 4288519581, 4288585374, 4288651167,
	4288716960, 4288782753, 4288848546, 4288914339, 4288980132, 4289045925, 4289111718, 4289177511,
	4289243304, 4289309097, 4289374890, 4289440683, 4289506476, 4289572269, 4289638062, 4289703855,
	4289769648, 4289835441, 4289901234, 4289967027, 4290032820, 4290098613, 4290164406, 4290230199,
	4290295992, 4290361785, 4290427578, 4290493371, 4290559164, 4290624957, 4290690750, 4290756543,
	4290822336, 4290888129, 4290953922, 4291019715, 4291085508, 4291151301, 4291217094, 4291282887,
	4291348680, 4291414473, 4291480266, 4291546059, 4291611852, 4291677645, 4291743438, 4291809231,
	4291875024, 4291940817, 4292006610, 4292072403, 4292138196, 4292203989, 4292269782, 4292335575,
	4292401368, 4292467161, 4292532954, 4292598747, 4292664540, 4292730333, 4292796126, 4292861919,
	4292927712, 4292993505, 4293059298, 4293125091, 4293190884, 4293256677, 4293322470, 4293388263,
	4293454056, 4293519849, 4293585642, 4293651435, 4293717228, 4293783021, 4293848814, 4293914607,
	4293980400, 4294046193, 4294111986, 4294177779, 4294243572, 4294309365, 4294375158, 4294440951,
	4294506744, 4294572537, 4294638330, 4294704123, 4294769916, 4294835709, 4294901502, 4294967295
};
