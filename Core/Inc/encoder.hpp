#define PI 3.14159265358979f
#include "tim.h"

class Encoder
{
public:
  TIM_HandleTypeDef *henc;
  int16_t cpr; // count per revolution
  uint32_t sample_time; // time to sample for omega
  float omega;
  //  int64_t count_aggregate = 0;
  uint32_t last_reset_time = 0;

 public:
  Encoder(TIM_HandleTypeDef *_henc, int16_t _cpr, uint32_t _sample_time = 1)
  {
   henc = _henc;
   cpr = _cpr;
   sample_time = _sample_time;
   init();
  }

  //  ~encoder() = default;
  void init();
  float get_encoder_omega();
  int32_t get_count();
  //  int64_t get_count_aggregate();
  void reset_encoder_count();
};
