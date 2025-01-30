/**
  ******************************************************************************
  * @file    Sd2Card.h
  * @author  Frederic Pillon <frederic.pillon@st.com> for STMicroelectronics
  * @date    2017
  * @brief
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#ifndef Sd2Card_h
#define Sd2Card_h

#include "bsp_sd.h"

#define SD_CARD_ERROR_NONE                    HAL_SD_ERROR_NONE
#define SD_CARD_ERROR_CMD_CRC_FAIL            HAL_SD_ERROR_CMD_CRC_FAIL
#define SD_CARD_ERROR_DATA_CRC_FAIL           HAL_SD_ERROR_DATA_CRC_FAIL
#define SD_CARD_ERROR_CMD_RSP_TIMEOUT         HAL_SD_ERROR_CMD_RSP_TIMEOUT
#define SD_CARD_ERROR_DATA_TIMEOUT            HAL_SD_ERROR_DATA_TIMEOUT
#define SD_CARD_ERROR_TX_UNDERRUN             HAL_SD_ERROR_TX_UNDERRUN
#define SD_CARD_ERROR_RX_OVERRUN              HAL_SD_ERROR_RX_OVERRUN
#define SD_CARD_ERROR_ADDR_MISALIGNED         HAL_SD_ERROR_ADDR_MISALIGNED
#define SD_CARD_ERROR_BLOCK_LEN_ERR           HAL_SD_ERROR_BLOCK_LEN_ERR
#define SD_CARD_ERROR_ERASE_SEQ_ERR           HAL_SD_ERROR_ERASE_SEQ_ERR
#define SD_CARD_ERROR_BAD_ERASE_PARAM         HAL_SD_ERROR_BAD_ERASE_PARAM
#define SD_CARD_ERROR_WRITE_PROT_VIOLATION    HAL_SD_ERROR_WRITE_PROT_VIOLATION
#define SD_CARD_ERROR_LOCK_UNLOCK_FAILED      HAL_SD_ERROR_LOCK_UNLOCK_FAILED
#define SD_CARD_ERROR_COM_CRC_FAILED          HAL_SD_ERROR_COM_CRC_FAILED
#define SD_CARD_ERROR_ILLEGAL_CMD             HAL_SD_ERROR_ILLEGAL_CMD
#define SD_CARD_ERROR_CARD_ECC_FAILED         HAL_SD_ERROR_CARD_ECC_FAILED
#define SD_CARD_ERROR_CC_ERR                  HAL_SD_ERROR_CC_ERR
#define SD_CARD_ERROR_GENERAL_UNKNOWN_ERR     HAL_SD_ERROR_GENERAL_UNKNOWN_ERR
#define SD_CARD_ERROR_STREAM_READ_UNDERRUN    HAL_SD_ERROR_STREAM_READ_UNDERRUN
#define SD_CARD_ERROR_STREAM_WRITE_OVERRUN    HAL_SD_ERROR_STREAM_WRITE_OVERRUN
#define SD_CARD_ERROR_CID_CSD_OVERWRITE       HAL_SD_ERROR_CID_CSD_OVERWRITE
#define SD_CARD_ERROR_WP_ERASE_SKIP           HAL_SD_ERROR_WP_ERASE_SKIP
#define SD_CARD_ERROR_CARD_ECC_DISABLED       HAL_SD_ERROR_CARD_ECC_DISABLED
#define SD_CARD_ERROR_ERASE_RESET             HAL_SD_ERROR_ERASE_RESET
#define SD_CARD_ERROR_AKE_SEQ_ERR             HAL_SD_ERROR_AKE_SEQ_ERR
#define SD_CARD_ERROR_INVALID_VOLTRANGE       HAL_SD_ERROR_INVALID_VOLTRANGE
#define SD_CARD_ERROR_ADDR_OUT_OF_RANGE       HAL_SD_ERROR_ADDR_OUT_OF_RANGE
#define SD_CARD_ERROR_REQUEST_NOT_APPLICABLE  HAL_SD_ERROR_REQUEST_NOT_APPLICABLE
#define SD_CARD_ERROR_PARAM                   HAL_SD_ERROR_PARAM
#define SD_CARD_ERROR_UNSUPPORTED_FEATURE     HAL_SD_ERROR_UNSUPPORTED_FEATURE
#define SD_CARD_ERROR_BUSY                    HAL_SD_ERROR_BUSY
#define SD_CARD_ERROR_DMA                     HAL_SD_ERROR_DMA
#define SD_CARD_ERROR_TIMEOUT                 HAL_SD_ERROR_TIMEOUT
#define SD_CARD_ERROR_INVALID                 0xFFFFFFFF

// card types to match Arduino definition
#define SD_CARD_TYPE_UNK      0
// back compatibility
#define SD_CARD_TYPE_UKN      SD_CARD_TYPE_UNK
/** Standard capacity V1 SD card */
#define SD_CARD_TYPE_SD1      1
/** Standard capacity V2 SD card */
#define SD_CARD_TYPE_SD2      2
/** High Capacity SD card */
#define SD_CARD_TYPE_SDHC     3
/** High Capacity SD card */
#define SD_CARD_TYPE_SECURED  4

class Sd2Card {
  public:
    Sd2Card();

    bool init(uint32_t detect = SD_DETECT_NONE, uint32_t level = SD_DETECT_LEVEL);
    bool deinit(void);

    // set* have to be called before init()
    void setDx(uint32_t data0, uint32_t data1 = PNUM_NOT_DEFINED, uint32_t data2 = PNUM_NOT_DEFINED, uint32_t data3 = PNUM_NOT_DEFINED)
    {
      SD_PinNames.pin_d0 = digitalPinToPinName(data0);
      SD_PinNames.pin_d1 = digitalPinToPinName(data1);
      SD_PinNames.pin_d2 = digitalPinToPinName(data2);
      SD_PinNames.pin_d3 = digitalPinToPinName(data3);
    };
    void setCK(uint32_t ck)
    {
      SD_PinNames.pin_ck = digitalPinToPinName(ck);
    };
    void setCMD(uint32_t cmd)
    {
      SD_PinNames.pin_cmd = digitalPinToPinName(cmd);
    };

    void setDx(PinName data0, PinName data1 = NC, PinName data2 = NC, PinName data3 = NC)
    {
      SD_PinNames.pin_d0 = data0;
      SD_PinNames.pin_d1 = data1;
      SD_PinNames.pin_d2 = data2;
      SD_PinNames.pin_d3 = data3;
    };
    void setCK(PinName ck)
    {
      SD_PinNames.pin_ck = ck;
    };
    void setCMD(PinName cmd)
    {
      SD_PinNames.pin_cmd = cmd;
    };
#if defined(SDMMC1) || defined(SDMMC2)
    void setCKIN(uint32_t ckin)
    {
      SD_PinNames.pin_ckin = digitalPinToPinName(ckin);
    };
    void setCDIR(uint32_t cdir)
    {
      SD_PinNames.pin_cdir = digitalPinToPinName(cdir);
    };
    void setDxDIR(uint32_t d0dir, uint32_t d123dir)
    {
      SD_PinNames.pin_d0dir = digitalPinToPinName(d0dir);
      SD_PinNames.pin_d123dir = digitalPinToPinName(d123dir);
    };

    void setCKIN(PinName ckin)
    {
      SD_PinNames.pin_ckin = ckin;
    };
    void setCDIR(PinName cdir)
    {
      SD_PinNames.pin_cdir = cdir;
    };
    void setDxDIR(PinName d0dir, PinName d123dir)
    {
      SD_PinNames.pin_d0dir = d0dir;
      SD_PinNames.pin_d123dir = d123dir;
    };
#endif
    /**
       Read a cards CID register. The CID contains card identification
       information such as Manufacturer ID, Product name, Product serial
       number and Manufacturing date. */
    bool readCID(BSP_SD_CardCID *cid)
    {
      return BSP_SD_GetCardCID(cid);
    }
    /**
       Read a cards CSD register. The CSD contains Card-Specific Data that
       provides information regarding access to the card's contents. */
    bool readCSD(BSP_SD_CardCSD *csd)
    {
      return BSP_SD_GetCardCSD(csd);
    }

    /** Return the card type: SD V1, SD V2 or SDHC */
    uint8_t type(void) const;

    /**
      Return The number of 512 byte data blocks in the card
      or zero if an error occurs.
    */
    uint32_t capacity(void) const
    {
      return _SdCardInfo.LogBlockNbr;
    }
    uint8_t manufacturerID(void) const
    {
      return _SdCardCID.ManufacturerID;
    };
    char *oemID(void)
    {
      _oemID[0] = (char)(_SdCardCID.OEM_AppliID >> 8);
      _oemID[1] = (char)(_SdCardCID.OEM_AppliID & 0xFF);
      _oemID[2] = '\0';
      return _oemID;
    };
    uint8_t productMajorRevision(void) const
    {
      return _SdCardCID.ProdRev >> 4;
    };
    uint8_t productMinorRevision(void) const
    {
      return _SdCardCID.ProdRev & 0xF;
    };
    uint32_t serialNumber(void) const
    {
      return _SdCardCID.ProdSN;
    };
    uint16_t manufacturingMonth(void) const
    {
      return (_SdCardCID.ManufactDate & 0xF);
    };
    uint16_t manufacturingYear(void) const
    {
      // Year is from 2000 +  Year high bits + Year low bits
      return (2000
              + (_SdCardCID.ManufactDate & 0xF0 >> 4)
              + (_SdCardCID.ManufactDate & 0xF00 >> 8)
             );
    };
    char *productName(void)
    {
      // ProdName1 is big endian and need to be swapped
      _prodName[3] = (char)(_SdCardCID.ProdName1 & 0xFF);
      _prodName[2] = (char)((_SdCardCID.ProdName1 & 0xFF00) >> 8);
      _prodName[1] = (char)((_SdCardCID.ProdName1 & 0xFF0000) >> 16);
      _prodName[0] = (char)((_SdCardCID.ProdName1 & 0xFF000000) >> 24);
      _prodName[4] = (char)(_SdCardCID.ProdName2);
      _prodName[5] = '\0';
      return _prodName;
    };
    uint32_t errorCode(void) const
    {
      return BSP_SD_ErrorCode();
    };
  private:
    char _prodName[6];
    char _oemID[3];
    BSP_SD_CardCID  _SdCardCID;
    BSP_SD_CardCSD  _SdCardCSD;
    BSP_SD_CardInfo _SdCardInfo;

};
#endif  // sd2Card_h
