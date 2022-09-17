#include <stdio.h>

#define off 0 // this for the states
#define on 1  // this for the states

char input ;  // this for the console input

typedef struct { // vehicle information
	char vehicle_speed ;
	char room_temperature;
	int engine_temperature;
	char engine_state ;
	char ac_state;
	char engine_temperature_controller_state ;
} vehicle;
vehicle v1;

void the_openning_of_the_program (void);
void sensors_set_menu (void);
void set_the_traffic_light_color (void);
void set_the_room_temperature (void);
void set_the_engine_temperature (void);
void choosing_main_option (char const*);
void choosing_sensor_option (char const*);
void displaying_values (void);
void checking_vehicle_speed (void);


int main ()
{
	v1.ac_state=off;
	v1.engine_state =off;
	v1.engine_temperature=120;
	v1.engine_temperature_controller_state=off;
	v1.room_temperature =25;
	v1.vehicle_speed=120;
	// initial conditions
	the_openning_of_the_program ();
}

void the_openning_of_the_program (void)
{
	printf(" Welcome! , how can i help you ? \n");
	fflush(stdout);
	printf("	a. Turn on the vehicle engine \n");
	fflush(stdout);
	printf("	b. Turn off the vehicle engine \n");
	fflush(stdout);
	printf("	c. Quit the system \n\n");
	fflush(stdout);
	scanf(" %c" ,&input);
    choosing_main_option (&input);
}

void choosing_main_option (char const*input)
{
	if (*input == 'a')
	{
		printf("a. Turn on the vehicle engine \n");
		fflush(stdout);
		sensors_set_menu ();
	}
	else if (*input == 'b')
	{
		printf("b. Turn off the vehicle engine \n");
		fflush(stdout);
		the_openning_of_the_program ();

	}
	else if (*input == 'c')
	{
	}
	else
	{
		printf(" press a valid option \n");
		fflush(stdout);
		the_openning_of_the_program ();

	}
}

void sensors_set_menu (void)
{

	printf("	a. Turn off the engine \n");
	fflush(stdout);
	printf("	b. Set the traffic light color \n");
	fflush(stdout);
	printf("	c. Set the room temperature \n");
	fflush(stdout);
	printf("	d. Set the engine temperature \n\n");
	fflush(stdout);
	scanf(" %c" ,&input);
	choosing_sensor_option (&input);

}

void choosing_sensor_option (char const*input)
{
	if (*input == 'a')
		{
			printf("a. Turn off the engine \n");
			fflush(stdout);
			the_openning_of_the_program ();
		}
		else if (*input == 'b')
		{
			printf("b. Set the traffic light color \n");
			fflush(stdout);
			set_the_traffic_light_color ();

		}
		else if (*input == 'c')
		{
			printf("c. Set the room temperature \n");
			fflush(stdout);
			set_the_room_temperature();
		}
		else if (*input == 'd')
		{
			printf("d. Set the engine temperature \n");
			fflush(stdout);
			set_the_engine_temperature();
		}
	else
		{
		printf(" press a valid option \n");
			fflush(stdout);
			sensors_set_menu ();
		}

}

void set_the_traffic_light_color (void)
{
	char looping_condition =0;
	do
	{
		printf("please enter the color \n");
		fflush(stdout);
		scanf(" %c" ,&input);
		switch (input)
		{
			case 'g' :
			case 'G' :
				v1.vehicle_speed=100;
				break;
			case 'o' :
			case 'O' :
				v1.vehicle_speed=30;
				break;
			case 'r' :
			case 'R' :
				v1.vehicle_speed=0;
				break;
			default :
				printf("please insert a valid option \n");
				looping_condition=1;
		}
	} while (looping_condition);
	looping_condition =0 ; // 3ashan lma agy asta5demo tany yeb2a l default b zero
	displaying_values();
}

void set_the_room_temperature (void)
{
	printf("please enter the temperature \n");
	fflush(stdout);
	scanf (" %d" ,&v1.room_temperature);


	if ((v1.room_temperature) < 10)
	{
		v1.ac_state= on;
		v1.room_temperature=20;
	}
	else if ((v1.room_temperature) > 30)
	{
		v1.ac_state= on;
		v1.room_temperature=20;
	}
	else
	{
		v1.ac_state= off;
	}
	displaying_values();
}

void set_the_engine_temperature (void)
{
	printf("please enter the engine temperature \n");
	fflush(stdout);
	scanf (" %d" ,&v1.engine_temperature);

	if (v1.engine_temperature < 100)
		{
			v1.engine_temperature_controller_state= on;
			v1.engine_temperature=125;
		}
		else if (v1.engine_temperature > 150)
		{
			v1.engine_temperature_controller_state= on;
			v1.engine_temperature=125;
		}
		else
		{
			v1.engine_temperature_controller_state= off;
		}
	displaying_values();
}

void displaying_values (void)
{
	checking_vehicle_speed ();
	v1.engine_state ? printf("i. Engine state is : on \n"):printf("i. Engine state is : off \n");
	//printf("i. Engine state is : %d \n" ,v1.engine_state);
	v1.ac_state ? printf("ii. AC is : on \n"):printf("ii. AC is : off \n");
	//printf("ii. AC is : %d \n" ,v1.ac_state);
	printf("iii. Vehicle Speed is : %d km/hr \n" , v1.vehicle_speed);
	printf("iv. Room Temperature is : %d C \n" , v1.room_temperature);
	v1.engine_temperature_controller_state?printf("v. Engine Temperature Controller State is : on \n"):
			printf("v. Engine Temperature Controller State is : off \n");
	//printf("v. Engine Temperature Controller State is : %d \n" ,v1.engine_temperature_controller_state);
	printf("vi. Engine Temperature is : %d \n \n" , v1.engine_temperature);
	sensors_set_menu ();
}

void checking_vehicle_speed (void)
{
	if (v1.vehicle_speed ==30)
	{
		v1.ac_state=on;
		v1.room_temperature = v1.room_temperature * 5/4 +1 ;
		v1.engine_temperature_controller_state=on;
		v1.engine_temperature = v1.engine_temperature * 5/4 +1 ;
	}
}

