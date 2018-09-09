// If we use the || approach, we start with the high region:
void print_blood_pressure(long systolic, long diastolic)
{
	if (systolic > 140 || diastolic > 90) {
		cs1010_println_string("high");
	} else if (systolic > 120 || diastolic > 80) {
		cs1010_println_string("pre-high");
	} else if (systolic > 90 || diastolic > 60) {
		cs1010_println_string("ideal");
	} else {
		cs1010_println_string("low");
	}
}

// If we use the && approach, we start with the low region:
void print_blood_pressure(long systolic, long diastolic) {
	if (systolic < 90 && diastolic < 60) {
		cs1010_println_string("low");
	} else if (systolic < 120 && diastolic < 80) {
		cs1010_println_string("ideal");
	} else if (systolic < 140 && diastolic < 90) {
		cs1010_println_string("pre-high");
	} else {
		cs1010_println_string("high");
	}
}