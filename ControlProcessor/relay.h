#define MAX_RELAYS 4

int relay_pinout[MAX_RELAYS] = {2, 3, 5, 6};
int relay_states[MAX_RELAYS] = {0, 0, 0, 0};

int relay_index = 0;
int relay_state = 0;

void init_control_relays(){
  for(int i=0; i < MAX_RELAYS; i++){
    pinMode(relay_pinout[i], OUTPUT);
    digitalWrite(relay_pinout[i], HIGH);
  }
}

void set_relay_state(int relay_id, int state){
    if(relay_id >= 0 && relay_id <= MAX_RELAYS-1){
      digitalWrite(relay_pinout[relay_id], state);  
    }
}

void drive_relays(char * command_buffer){
  relay_index = ((int) command_buffer[0]) - 0x30;
  relay_state = ((int) command_buffer[1]) - 0x30;
  set_relay_state(relay_index, relay_state);
}
