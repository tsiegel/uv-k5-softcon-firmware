
#ifdef ENABLE_DOCK
	#define VER		"0_32_21q"
#else
	#ifdef VERSION_STRING
		#define VER     "softcon 1.0"VERSION_STRING
	#else
		#define VER     ""
	#endif
#endif

const char Version[]      = AUTHOR_STRING VER;
const char UART_Version[] = "UV-K5 Firmware, Open Edition, " VER "\r\n";

