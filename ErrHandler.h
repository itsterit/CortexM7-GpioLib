#ifdef __cplusplus
extern "C"
{
#endif
#ifndef ERRHANDLER_H
#define ERRHANDLER_H

typedef long int ErrHandle_t;

#define STM_OK                      0       /*!< esp_err_t value indicating success (no error) */
#define STM_FAIL                    -1      /*!< Generic esp_err_t code indicating failure */
#define STM_ERR_NO_MEM              0x101   /*!< Out of memory */
#define STM_ERR_INVALID_ARG         0x102   /*!< Invalid argument */
#define STM_ERR_INVALID_STATE       0x103   /*!< Invalid state */
#define STM_ERR_INVALID_SIZE        0x104   /*!< Invalid size */
#define STM_ERR_NOT_FOUND           0x105   /*!< Requested resource not found */
#define STM_ERR_NOT_SUPPORTED       0x106   /*!< Operation or feature not supported */
#define STM_ERR_TIMEOUT             0x107   /*!< Operation timed out */
#define STM_ERR_INVALID_RESPONSE    0x108   /*!< Received response was invalid */
#define STM_ERR_INVALID_CRC         0x109   /*!< CRC or checksum was invalid */
#define STM_ERR_INVALID_VERSION     0x10A   /*!< Version was invalid */
#define STM_ERR_INVALID_MAC         0x10B   /*!< MAC address was invalid */
#define STM_ERR_WIFI_BASE           0x3000  /*!< Starting number of WiFi error codes */
#define STM_ERR_MESH_BASE           0x4000  /*!< Starting number of MESH error codes */
#define STM_ERR_FLASH_BASE          0x6000  /*!< Starting number of flash error codes */

#endif /* ERRHANDLER_H */
#ifdef __cplusplus
}
#endif