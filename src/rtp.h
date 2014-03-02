#ifndef _RTSP_RTP_H
#define _RTSP_RTP_H

#if defined (__cplusplus)
extern "C" {
#endif

/******************************************************************************
 *              DEFINITIONS 
 ******************************************************************************/
#define __RTP_MAXPAYLOADSIZE 1460

/******************************************************************************
 *              DATA STRUCTURES
 ******************************************************************************/
struct nal_rtp_t {
    struct {
        rtp_hdr_t header;
        signed char payload[__RTP_MAXPAYLOADSIZE];
    } packet;
    int    rtpsize;
    struct list_t list_entry;
};

/******************************************************************************
 *              DECLARATIONS
 ******************************************************************************/
static inline int __split_nal(signed char *buf, signed char **nalptr, size_t *p_len, size_t max_len);

/******************************************************************************
 *              INLINE FUNCTIONS
 ******************************************************************************/
static inline int __split_nal(signed char *buf, signed char **nalptr, size_t *p_len, size_t max_len)
{
    int i;
    int start = -1;

    for(i = (*nalptr) - buf + *p_len;i<max_len-5;i++) {
        if(buf[i] == 0x00 &&
                buf[i+1] == 0x00 &&
                buf[i+2] == 0x00 &&
                buf[i+3] == 0x01) {
            if(start == -1){
                i += 4;
                start = i;
            } else {
                *nalptr = &(buf[start]);
                while(buf[i-1] == 0) i--;
                *p_len = i - start;
                return SUCCESS;
            }
        }
    }

    if(start == -1) {
        /* malformed NAL */
        return FAILURE;
    }

    *nalptr = &(buf[start]);
    *p_len = max_len + 2 - start;

    return SUCCESS;
}

#if defined (__cplusplus)
}
#endif

#endif
