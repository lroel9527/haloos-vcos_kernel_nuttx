#include "bsp_api.h"
#include "r_ioport_api.h"
#include "r_ioport.h"

const ioport_extend_cfg_t g_ioport_cfg_extend =
    {
        .nf_cfg =
            {
                .nf_enable_cfg =
                    {
                        .noise_filter_enable_rlin = (0ULL),
                        .noise_filter_enable_rscan = (0ULL),
                        .noise_filter_enable_flxa = (0ULL),
                        .noise_filter_enable_sent0 = (0ULL),
                        .noise_filter_enable_sent1 = (0ULL),
                        .noise_filter_enable_psi5 = (0ULL),
                        .noise_filter_enable_pic_tapa = (0ULL),
                        .noise_filter_enable_adcj0 = (0ULL),
                        .noise_filter_enable_adcj1 = (0ULL),
                        .noise_filter_enable_adcj2 = (0ULL),
                        .noise_filter_enable_adck0 = (0ULL),
                        .noise_filter_enable_adck1 = (0ULL),
                        .noise_filter_enable_adck2 = (0ULL),
                        .noise_filter_enable_adck3 = (0ULL),
                        .noise_filter_enable_adcka = (0ULL),
                        .noise_filter_enable_rhsb = (0ULL),
                        .noise_filter_enable_enca = (0ULL),
                        .noise_filter_enable_taud0 = (0ULL),
                        .noise_filter_enable_taud1 = (0ULL),
                        .noise_filter_enable_taud2 = (0ULL),
                        .noise_filter_enable_taud3 = (0ULL),
                        .noise_filter_enable_tsg3 = (0ULL),
                        .noise_filter_enable_ecm = (0ULL),
                        .noise_filter_enable_tauj0 = (0ULL),
                        .noise_filter_enable_tauj1 = (0ULL),
                        .noise_filter_enable_tauj2 = (0ULL),
                        .noise_filter_enable_tauj3 = (0ULL),
                        .noise_filter_enable_pic_tsg = (0ULL),
                        .noise_filter_enable_emu = (0ULL),
                        .noise_filter_enable_ssif = (0ULL),
                        .noise_filter_enable_ospi0 = (0ULL),
                        .noise_filter_enable_esr0_irq0 = (0ULL),
                        .noise_filter_enable_esr0_nmi = (0ULL),
                        .noise_filter_enable_esr1_nmi = (0ULL),
                    },
                .nf_filter_cfg =
                    {

#if BSP_FEATURE_IOPORT_NF_RLIN30
                        [IOPORT_FILTER_SIGNAL_RLIN30RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RLIN31
                        [IOPORT_FILTER_SIGNAL_RLIN31RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSCAN
                        [IOPORT_FILTER_SIGNAL_CAN0RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_CAN1RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_FLXA0
                        [IOPORT_FILTER_SIGNAL_FLXA0RXDA] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_FLXA1
                        [IOPORT_FILTER_SIGNAL_FLXA1RXDA] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT0
                        [IOPORT_FILTER_SIGNAL_SENT0RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT1
                        [IOPORT_FILTER_SIGNAL_SENT1RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT2
                        [IOPORT_FILTER_SIGNAL_SENT2RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT3
                        [IOPORT_FILTER_SIGNAL_SENT3RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT4
                        [IOPORT_FILTER_SIGNAL_SENT4RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT5
                        [IOPORT_FILTER_SIGNAL_SENT5RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT6
                        [IOPORT_FILTER_SIGNAL_SENT6RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT7
                        [IOPORT_FILTER_SIGNAL_SENT7RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT8
                        [IOPORT_FILTER_SIGNAL_SENT8RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT9
                        [IOPORT_FILTER_SIGNAL_SENT9RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT10
                        [IOPORT_FILTER_SIGNAL_SENT10RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT11
                        [IOPORT_FILTER_SIGNAL_SENT11RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT12
                        [IOPORT_FILTER_SIGNAL_SENT12RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT13
                        [IOPORT_FILTER_SIGNAL_SENT13RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT14
                        [IOPORT_FILTER_SIGNAL_SENT14RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT15
                        [IOPORT_FILTER_SIGNAL_SENT15RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT16
                        [IOPORT_FILTER_SIGNAL_SENT16RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT17
                        [IOPORT_FILTER_SIGNAL_SENT17RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT18
                        [IOPORT_FILTER_SIGNAL_SENT18RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT19
                        [IOPORT_FILTER_SIGNAL_SENT19RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT20
                        [IOPORT_FILTER_SIGNAL_SENT20RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT21
                        [IOPORT_FILTER_SIGNAL_SENT21RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT22
                        [IOPORT_FILTER_SIGNAL_SENT22RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT23
                        [IOPORT_FILTER_SIGNAL_SENT23RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT24
                        [IOPORT_FILTER_SIGNAL_SENT24RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT25
                        [IOPORT_FILTER_SIGNAL_SENT25RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT26
                        [IOPORT_FILTER_SIGNAL_SENT26RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT27
                        [IOPORT_FILTER_SIGNAL_SENT27RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT28
                        [IOPORT_FILTER_SIGNAL_SENT28RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RSENT29
                        [IOPORT_FILTER_SIGNAL_SENT29RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PSI50
                        [IOPORT_FILTER_SIGNAL_PSI50RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PSI51
                        [IOPORT_FILTER_SIGNAL_PSI51RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PSI52
                        [IOPORT_FILTER_SIGNAL_PSI52RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PSI53
                        [IOPORT_FILTER_SIGNAL_PSI53RX] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA0
                        [IOPORT_FILTER_SIGNAL_INTTAPA0ESO_TAPA0ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA1
                        [IOPORT_FILTER_SIGNAL_INTTAPA1ESO_TAPA1ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA2
                        [IOPORT_FILTER_SIGNAL_INTTAPA2ESO_TAPA2ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA3
                        [IOPORT_FILTER_SIGNAL_INTTAPA3ESO_TAPA3ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA4
                        [IOPORT_FILTER_SIGNAL_INTTAPA4ESO_TAPA4ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TAPA5
                        [IOPORT_FILTER_SIGNAL_INTTAPA5ESO_TAPA5ESO] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCJ0
                        [IOPORT_FILTER_SIGNAL_ADCJ0TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ0TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ0TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ0TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ0TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCJ1
                        [IOPORT_FILTER_SIGNAL_ADCJ1TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ1TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ1TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ1TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCJ1TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCJ2
                        [IOPORT_FILTER_SIGNAL_ADCJ2TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCJ2TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCJ2TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCJ2TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCJ2TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCK0
                        [IOPORT_FILTER_SIGNAL_ADCK0TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK0TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK0TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK0TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK0TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCK1
                        [IOPORT_FILTER_SIGNAL_ADCK1TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK1TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK1TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK1TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK1TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCK2
                        [IOPORT_FILTER_SIGNAL_ADCK2TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK2TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK2TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK2TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK2TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCK3
                        [IOPORT_FILTER_SIGNAL_ADCK3TRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK3TRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK3TRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK3TRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
                        [IOPORT_FILTER_SIGNAL_ADCK3TRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ADCKA
                        [IOPORT_FILTER_SIGNAL_ADCKATRG0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCKATRG1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCKATRG2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCKATRG3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_ADCKATRG4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_RHSB0
                        [IOPORT_FILTER_SIGNAL_RHSB0EMRG] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_RHSB1
                        [IOPORT_FILTER_SIGNAL_RHSB1EMRG] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_RHSB2
                        [IOPORT_FILTER_SIGNAL_RHSB2EMRG] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_RHSB3
                        [IOPORT_FILTER_SIGNAL_RHSB3EMRG] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1},
#endif
#if BSP_FEATURE_IOPORT_NF_ENCA0
                        [IOPORT_FILTER_SIGNAL_ENCA0TIN0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_ENCA0TIN1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ENCA1
                        [IOPORT_FILTER_SIGNAL_ENCA1TIN0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_ENCA1TIN1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM0
                        [IOPORT_FILTER_SIGNAL_ERRORIN0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM1
                        [IOPORT_FILTER_SIGNAL_ERRORIN1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM2
                        [IOPORT_FILTER_SIGNAL_ERRORIN2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM3
                        [IOPORT_FILTER_SIGNAL_ERRORIN3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM4
                        [IOPORT_FILTER_SIGNAL_ERRORIN4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM5
                        [IOPORT_FILTER_SIGNAL_ERRORIN5] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM6
                        [IOPORT_FILTER_SIGNAL_ERRORIN6] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_ECM7
                        [IOPORT_FILTER_SIGNAL_ERRORIN7] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TAUD0
                        [IOPORT_FILTER_SIGNAL_TAUD0I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I5] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I6] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I7] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I8] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I9] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I10] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I11] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I12] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I13] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I14] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD0I15] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TAUD1
                        [IOPORT_FILTER_SIGNAL_TAUD1I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I5] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I6] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I7] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I8] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I9] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I10] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I11] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I12] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I13] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I14] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD1I15] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TAUD2
                        [IOPORT_FILTER_SIGNAL_TAUD2I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I5] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I6] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I7] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I8] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I9] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I10] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I11] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I12] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I13] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I14] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD2I15] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TAUD3
                        [IOPORT_FILTER_SIGNAL_TAUD3I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I4] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I5] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I6] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I7] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I8] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I9] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I10] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I11] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I12] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I13] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I14] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TAUD3I15] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TAUJ0
                        [IOPORT_FILTER_SIGNAL_TAUJ0I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ0I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ0I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ0I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_TAUJ1
                        [IOPORT_FILTER_SIGNAL_TAUJ1I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ1I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ1I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ1I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_TAUJ2
                        [IOPORT_FILTER_SIGNAL_TAUJ2I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ2I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ2I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ2I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_TAUJ3
                        [IOPORT_FILTER_SIGNAL_TAUJ3I0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ3I1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ3I2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
                        [IOPORT_FILTER_SIGNAL_TAUJ3I3] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL},
#endif
#if BSP_FEATURE_IOPORT_NF_PIC_TSG
                        [IOPORT_FILTER_SIGNAL_TSGTRG] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_EMU0
                        [IOPORT_FILTER_SIGNAL_EM00_IN_A] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_EM00_IN_B] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_EM00_IN_Z] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_EMU1
                        [IOPORT_FILTER_SIGNAL_EM10_IN_A] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_EM10_IN_B] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_EM10_IN_Z] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_OSPI0
                        [IOPORT_FILTER_SIGNAL_OSPI0INT0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_OSPI0INT1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_OSPI0ECS0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_OSPI0ECS1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TSG30
                        [IOPORT_FILTER_SIGNAL_TSG30PTSI0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG30PTSI1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG30PTSI2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG30CLKI] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TSG31
                        [IOPORT_FILTER_SIGNAL_TSG31PTSI0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG31PTSI1] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG31PTSI2] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_TSG31CLKI] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_TSG32
                        [IOPORT_FILTER_SIGNAL_TSG32CLKI] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_SSIF
                        [IOPORT_FILTER_SIGNAL_SSIF0BCK] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIF0LRCK_FS] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIF0RXD] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIFACK] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIF1BCK] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIF1LRCK_FS] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
                        [IOPORT_FILTER_SIGNAL_SSIF1RXD] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ0
                        [IOPORT_FILTER_SIGNAL_IRQ0] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ1
                        [IOPORT_FILTER_SIGNAL_IRQ1] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ2
                        [IOPORT_FILTER_SIGNAL_IRQ2] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ3
                        [IOPORT_FILTER_SIGNAL_IRQ3] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ4
                        [IOPORT_FILTER_SIGNAL_IRQ4] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ5
                        [IOPORT_FILTER_SIGNAL_IRQ5] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ6
                        [IOPORT_FILTER_SIGNAL_IRQ6] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ7
                        [IOPORT_FILTER_SIGNAL_IRQ7] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ8
                        [IOPORT_FILTER_SIGNAL_IRQ8] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ9
                        [IOPORT_FILTER_SIGNAL_IRQ9] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ10
                        [IOPORT_FILTER_SIGNAL_IRQ10] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ11
                        [IOPORT_FILTER_SIGNAL_IRQ11] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ12
                        [IOPORT_FILTER_SIGNAL_IRQ12] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ13
                        [IOPORT_FILTER_SIGNAL_IRQ13] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ14
                        [IOPORT_FILTER_SIGNAL_IRQ14] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ15
                        [IOPORT_FILTER_SIGNAL_IRQ15] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ16
                        [IOPORT_FILTER_SIGNAL_IRQ16] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ17
                        [IOPORT_FILTER_SIGNAL_IRQ17] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ18
                        [IOPORT_FILTER_SIGNAL_IRQ18] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ19
                        [IOPORT_FILTER_SIGNAL_IRQ19] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ20
                        [IOPORT_FILTER_SIGNAL_IRQ20] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ21
                        [IOPORT_FILTER_SIGNAL_IRQ21] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ22
                        [IOPORT_FILTER_SIGNAL_IRQ22] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ23
                        [IOPORT_FILTER_SIGNAL_IRQ23] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ24
                        [IOPORT_FILTER_SIGNAL_IRQ24] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ25
                        [IOPORT_FILTER_SIGNAL_IRQ25] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ26
                        [IOPORT_FILTER_SIGNAL_IRQ26] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ27
                        [IOPORT_FILTER_SIGNAL_IRQ27] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ28
                        [IOPORT_FILTER_SIGNAL_IRQ28] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ29
                        [IOPORT_FILTER_SIGNAL_IRQ29] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ30
                        [IOPORT_FILTER_SIGNAL_IRQ30] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ31
                        [IOPORT_FILTER_SIGNAL_IRQ31] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ32
                        [IOPORT_FILTER_SIGNAL_IRQ32] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ33
                        [IOPORT_FILTER_SIGNAL_IRQ33] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ34
                        [IOPORT_FILTER_SIGNAL_IRQ34] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ35
                        [IOPORT_FILTER_SIGNAL_IRQ35] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ36
                        [IOPORT_FILTER_SIGNAL_IRQ36] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ37
                        [IOPORT_FILTER_SIGNAL_IRQ37] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ38
                        [IOPORT_FILTER_SIGNAL_IRQ38] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ39
                        [IOPORT_FILTER_SIGNAL_IRQ39] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ40
                        [IOPORT_FILTER_SIGNAL_IRQ40] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ41
                        [IOPORT_FILTER_SIGNAL_IRQ41] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ42
                        [IOPORT_FILTER_SIGNAL_IRQ42] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ43
                        [IOPORT_FILTER_SIGNAL_IRQ43] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ44
                        [IOPORT_FILTER_SIGNAL_IRQ44] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ45
                        [IOPORT_FILTER_SIGNAL_IRQ45] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ_NMI
                        [IOPORT_FILTER_SIGNAL_NMI] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_IRQ_ESR
                        [IOPORT_FILTER_SIGNAL_ESR0_IRQ0] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
                        [IOPORT_FILTER_SIGNAL_ESR0_NMI] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
                        [IOPORT_FILTER_SIGNAL_ESR1_NMI] =
                            {
                                .number_sample = IOPORT_FILTER_SAMPLE_2,
                                .sampling_clock = IOPORT_FILTER_CLOCK_DIV_1,
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP_NMI
                        [IOPORT_FILTER_SIGNAL_INTP_NMI] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP0
                        [IOPORT_FILTER_SIGNAL_INTP0] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP1
                        [IOPORT_FILTER_SIGNAL_INTP1] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP2
                        [IOPORT_FILTER_SIGNAL_INTP2] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP3
                        [IOPORT_FILTER_SIGNAL_INTP3] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP4
                        [IOPORT_FILTER_SIGNAL_INTP4] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP5
                        [IOPORT_FILTER_SIGNAL_INTP5] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP6
                        [IOPORT_FILTER_SIGNAL_INTP6] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP7
                        [IOPORT_FILTER_SIGNAL_INTP7] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP8
                        [IOPORT_FILTER_SIGNAL_INTP8] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP9
                        [IOPORT_FILTER_SIGNAL_INTP9] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP10
                        [IOPORT_FILTER_SIGNAL_INTP10] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP11
                        [IOPORT_FILTER_SIGNAL_INTP11] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP12
                        [IOPORT_FILTER_SIGNAL_INTP12] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP13
                        [IOPORT_FILTER_SIGNAL_INTP13] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP14
                        [IOPORT_FILTER_SIGNAL_INTP14] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP15
                        [IOPORT_FILTER_SIGNAL_INTP15] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP16
                        [IOPORT_FILTER_SIGNAL_INTP16] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP17
                        [IOPORT_FILTER_SIGNAL_INTP17] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP18
                        [IOPORT_FILTER_SIGNAL_INTP18] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP19
                        [IOPORT_FILTER_SIGNAL_INTP19] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP20
                        [IOPORT_FILTER_SIGNAL_INTP20] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP21
                        [IOPORT_FILTER_SIGNAL_INTP21] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP22
                        [IOPORT_FILTER_SIGNAL_INTP22] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP23
                        [IOPORT_FILTER_SIGNAL_INTP23] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP24
                        [IOPORT_FILTER_SIGNAL_INTP24] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP25
                        [IOPORT_FILTER_SIGNAL_INTP25] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP26
                        [IOPORT_FILTER_SIGNAL_INTP26] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP27
                        [IOPORT_FILTER_SIGNAL_INTP27] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP28
                        [IOPORT_FILTER_SIGNAL_INTP28] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP29
                        [IOPORT_FILTER_SIGNAL_INTP29] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP30
                        [IOPORT_FILTER_SIGNAL_INTP30] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP31
                        [IOPORT_FILTER_SIGNAL_INTP31] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP32
                        [IOPORT_FILTER_SIGNAL_INTP32] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP33
                        [IOPORT_FILTER_SIGNAL_INTP33] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP34
                        [IOPORT_FILTER_SIGNAL_INTP34] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP35
                        [IOPORT_FILTER_SIGNAL_INTP35] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP36
                        [IOPORT_FILTER_SIGNAL_INTP36] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP37
                        [IOPORT_FILTER_SIGNAL_INTP37] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP38
                        [IOPORT_FILTER_SIGNAL_INTP38] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
#if BSP_FEATURE_IOPORT_NF_INTP39
                        [IOPORT_FILTER_SIGNAL_INTP39] =
                            {
                                .detection_mode = IOPORT_FILTER_DETECTION_DISABLE_EDGE,
                                .bypass_mode = IOPORT_FILTER_SELECT_SIGNAL,
                            },
#endif
                    },
            },
        .lvds_cfg =
            {.lvdsctrl_a = (0ULL),
             .lvdsctrl_b = (0ULL),
             .lvdsctrl_c = (0ULL),
             .lvdsctrl_d = (0ULL),
             .lvdsctrl_e = (0ULL),
             .lvdsctrl_f = (0ULL)},
        .pulvsel5_cfg = (0ULL),
};

const ioport_pin_cfg_t g_bsp_pin_cfg_data[] =
    {
        {
            .pin = BSP_IO_PORT_P00_PIN_1, // led0
            .pin_cfg = ((uint32_t)IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t)IOPORT_CFG_PORT_OUTPUT_LOW),
        },
        {
            //.pin = BSP_IO_PORT_P01_PIN_13, // RLIN30TX
            //.pin_cfg = ((uint32_t)IOPORT_ALT_OUT8 | (uint32_t)IOPORT_CFG_DRIVE_MEDIUM | (uint32_t)IOPORT_CFG_PERIPHERAL_PIN),
            .pin = BSP_IO_PORT_P02_PIN_2, // RLIN30TX
            .pin_cfg = ((uint32_t)IOPORT_ALT_OUT2 | (uint32_t)IOPORT_CFG_DRIVE_MEDIUM | (uint32_t)IOPORT_CFG_PERIPHERAL_PIN),
        },
        {
            //.pin = BSP_IO_PORT_P01_PIN_8, // RLIN30RX
            //.pin_cfg = ((uint32_t)IOPORT_ALT_IN8 | (uint32_t)IOPORT_CFG_PERIPHERAL_PIN),
		    .pin = BSP_IO_PORT_P02_PIN_3, // RLIN30RX
		    .pin_cfg = ((uint32_t)IOPORT_ALT_IN6 | (uint32_t)IOPORT_CFG_PERIPHERAL_PIN),

        },
};

const ioport_cfg_t g_bsp_pin_cfg =
    {.number_of_pins = sizeof(g_bsp_pin_cfg_data) / sizeof(ioport_pin_cfg_t),
     .p_pin_cfg_data = &g_bsp_pin_cfg_data[0],
     .p_extend = &g_ioport_cfg_extend};

ioport_instance_ctrl_t g_ioport_ctrl;

void rh850_ioportinit(void)
{
    /* Configure pins. */
    R_IOPORT_PinsCfg(&g_ioport_ctrl, &g_bsp_pin_cfg);
}
