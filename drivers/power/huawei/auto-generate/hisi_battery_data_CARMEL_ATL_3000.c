
/* DO NOT EDIT - Generated automatically by build.py */

static struct single_row_lut CARMEL_ATL_3000_fcc_temp = {
	.x		= {-20, -10, 0, 25, 40, 60},
	.y		= {3070, 3066, 3065, 3072, 3070, 3054},
	.cols	= 6
};

static struct single_row_lut CARMEL_ATL_3000_fcc_sf = {
	.x		= {0, 100, 200, 300, 400, 500},
	.y		= {100, 96, 94, 92, 90, 88},
	.cols	= 6
};

static struct sf_lut CARMEL_ATL_3000_pc_sf = {
	.rows = 1,
	.cols = 1,
	.row_entries = {0},
	.percent = {100},
	.sf = {
		{100}
	}
};


static struct sf_lut CARMEL_ATL_3000_rbatt_sf = {
	.rows = 28,
	.cols = 6,
	.row_entries = {-20, -10, 0, 25, 40, 60},
	.percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
	.sf = {
		{2290, 1210, 494, 141, 107, 97},
		{2285, 1210, 494, 141, 107, 97},
		{2104, 1186, 500, 144, 108, 97},
		{1968, 1149, 517, 147, 110, 99},
		{1892, 1158, 531, 153, 112, 100},
		{1766, 1084, 543, 161, 115, 102},
		{1758, 1040, 510, 172, 120, 104},
		{1752, 1036, 491, 184, 130, 109},
		{1761, 1031, 479, 179, 136, 114},
		{1783, 1045, 473, 147, 115, 103},
		{1821, 1072, 484, 140, 107, 98},
		{1880, 1118, 503, 141, 107, 99},
		{1971, 1181, 532, 144, 110, 100},
		{2087, 1269, 574, 147, 114, 103},
		{2232, 1386, 631, 148, 114, 103},
		{2406, 1539, 724, 147, 108, 97},
		{2631, 1730, 857, 149, 110, 99},
		{2961, 1950, 1073, 157, 112, 100},
		{6242, 2721, 1175, 157, 114, 102},
		{7106, 3134, 1346, 160, 116, 104},
		{8019, 3625, 1576, 169, 119, 105},
		{8983, 4147, 1861, 177, 121, 106},
		{10055, 4750, 2191, 189, 124, 108},
		{11181, 5473, 2560, 192, 125, 106},
		{12483, 6330, 3017, 197, 127, 108},
		{14129, 7343, 3634, 219, 133, 112},
		{19283, 8746, 4481, 263, 150, 123},
		{30983, 10749, 5544, 453, 354, 161},
	}
};

static struct pc_temp_ocv_lut CARMEL_ATL_3000_pc_temp_ocv = {
	.rows = 29,
	.cols = 6,
	.temp = {-20, -10, 0, 25, 40, 60},
	.percent = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv = {
		{4331, 4328, 4326, 4321, 4317, 4311},
		{4229, 4239, 4245, 4252, 4250, 4245},
		{4159, 4172, 4182, 4194, 4191, 4187},
		{4097, 4110, 4128, 4139, 4136, 4132},
		{4040, 4062, 4078, 4087, 4084, 4080},
		{3964, 3995, 4022, 4039, 4036, 4032},
		{3923, 3942, 3967, 3991, 3991, 3987},
		{3885, 3902, 3923, 3951, 3951, 3948},
		{3855, 3865, 3882, 3908, 3911, 3909},
		{3830, 3836, 3847, 3863, 3864, 3863},
		{3811, 3815, 3821, 3833, 3833, 3831},
		{3796, 3801, 3801, 3812, 3811, 3809},
		{3785, 3790, 3789, 3794, 3793, 3791},
		{3773, 3781, 3780, 3780, 3779, 3777},
		{3760, 3771, 3771, 3768, 3765, 3759},
		{3746, 3756, 3759, 3754, 3746, 3734},
		{3729, 3737, 3739, 3734, 3726, 3714},
		{3710, 3712, 3711, 3705, 3699, 3688},
		{3680, 3683, 3676, 3679, 3673, 3663},
		{3672, 3676, 3670, 3676, 3670, 3660},
		{3664, 3671, 3664, 3672, 3667, 3657},
		{3654, 3664, 3658, 3667, 3663, 3653},
		{3642, 3654, 3649, 3658, 3655, 3646},
		{3625, 3638, 3632, 3635, 3634, 3627},
		{3597, 3611, 3604, 3593, 3595, 3589},
		{3555, 3566, 3561, 3536, 3540, 3536},
		{3492, 3499, 3498, 3460, 3467, 3468},
		{3396, 3388, 3394, 3356, 3374, 3372},
		{3200, 3200, 3200, 3200, 3200, 3200},
	}
};

struct hisi_smartstar_coul_battery_data CARMEL_ATL_3000_battery_data = {
	.id_voltage_min = 130,
	.id_voltage_max = 330,
	.fcc = 3000,
	.fcc_temp_lut  = &CARMEL_ATL_3000_fcc_temp,
	.fcc_sf_lut = &CARMEL_ATL_3000_fcc_sf,
	.pc_temp_ocv_lut = &CARMEL_ATL_3000_pc_temp_ocv,
	.pc_sf_lut = &CARMEL_ATL_3000_pc_sf,
	.rbatt_sf_lut = &CARMEL_ATL_3000_rbatt_sf,
	.default_rbatt_mohm = 100,
	.max_currentmA = 1000,
    .max_voltagemV = 4352,
    .max_cin_currentmA = 1000,
    .terminal_currentmA = 150,
    .charge_in_temp_5 = 3,
    .charge_in_temp_10 = 3,
    .batt_brand = "CARMEL_ATL_3000",
};