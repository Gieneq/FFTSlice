#include "fftslice.h"
#include "dac.h"
#include "spi.h"
#include "gpio.h"
#include "tim.h"

void fftslice_init(fftslice_t* fftslice, fftslice_config_t* config) {
	int res;

	/* Init HAL perips */
	MX_DAC1_Init();
	//todo

	/* Init drivers */
	TS6A9411_init(&fftslice->selector, config->ts5a9411_select_sig_port, config->ts5a9411_select_sig_pin);
	MCP6S22_init(&fftslice->amplifier, config->mcp6s22_spi, config->mcp6s22_ncs_port, config->mcp6s22_ncs_pin);

	res = sig_generator_init(&fftslice->generator, &hdac1, &htim1);
	if(res != 0) {
		Error_Handler();
	}
	/* Init registers */
}


HAL_StatusTypeDef fftslice_select_signal_source(fftslice_t* fftslice, fftslice_signal_source_t source) {
	fftslice->source_signal = source;

	//stop DAC if not used
	return HAL_OK;
}


HAL_StatusTypeDef fftslice_set_amplifier_gain(fftslice_t* fftslice, fftslice_gain_t gain) {
	fftslice->gain = gain;
	/* is DAC selected divide samples ? */
	return HAL_OK;
}


