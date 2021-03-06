/*
 * Copyright (c) 2013-2015 TRUSTONIC LIMITED
 * All rights reserved
 *
 * The present software is the confidential and proprietary information of
 * TRUSTONIC LIMITED. You shall not disclose the present software and shall
 * use it only in accordance with the terms of the license agreement you
 * entered into with TRUSTONIC LIMITED. This software may be subject to
 * export or import laws in certain countries.
 */
/**
 * @addtogroup NQ
 * @{
 * Notifications inform the MobiCore runtime environment that information is pending in a WSM buffer.
 * The Trustlet Connector (TLC) and the corresponding trustlet also utilize this buffer to notify
 * each other about new data within the Trustlet Connector Interface (TCI).
 *
 * The buffer is set up as a queue, which means that more than one notification can be written to the buffer
 * before the switch to the other world is performed. Each side therefore facilitates an incoming and an
 * outgoing queue for communication with the other side.
 *
 * Notifications hold the session ID, which is used to reference the communication partner in the other world.
 * So if, e.g., the TLC in the normal world wants to notify his trustlet about new data in the TLC buffer
 *
 * @file
 * Notification queue declarations.
 *
 */

#ifndef NQ_H_
#define NQ_H_

/** \name NQ Size Defines
 * Minimum and maximum count of elements in the notification queue.
 * @{ */
#define MIN_NQ_ELEM 1   /**< Minimum notification queue elements. */
#define MAX_NQ_ELEM 64 /**< Maximum notification queue elements. */
/** @} */

/** \name NQ Length Defines
 * Note that there is one queue for NWd->SWd and one queue for SWd->NWd
 * @{ */
#define NQ_SIZE(n)   (2*(sizeof(notificationQueueHeader_t) + (n)*sizeof(notification_t)))
#define MIN_NQ_LEN NQ_SIZE(MIN_NQ_ELEM)   /**< Minimum size for the notification queue data structure */
#define MAX_NQ_LEN NQ_SIZE(MAX_NQ_ELEM)   /**< Maximum size for the notification queue data structure */
/** @} */

/** \name Session ID Defines
 * Standard Session IDs.
 * @{ */
#define SID_MCP       0           /**< MCP session ID is used when directly communicating with the MobiCore (e.g. for starting and stopping of trustlets). */
#define SID_INVALID   0xffffffff  /**< Invalid session id is returned in case of an error. */
/** @} */

/** Notification data structure. */
typedef struct{
    uint32_t sessionId; /**< Session ID. */
    int32_t payload;    /**< Additional notification information. */
} notification_t;

/** Notification payload codes.
 * 0 indicated a plain simple notification,
 * a positive value is a termination reason from the task,
 * a negative value is a termination reason from MobiCore.
 * Possible negative values are given below.
 */
typedef enum {
    ERR_INVALID_EXIT_CODE   = -1, /**< task terminated, but exit code is invalid */
    ERR_SESSION_CLOSE       = -2, /**< task terminated due to session end, no exit code available */
    ERR_INVALID_OPERATION   = -3, /**< task terminated due to invalid operation */
    ERR_INVALID_SID         = -4, /**< session ID is unknown */
    ERR_SID_NOT_ACTIVE      = -5, /**< session is not active */
    ERR_SESSION_KILLED      = -6, /**< session was force-killed (due to an administrative command). */
} notificationPayload_t;

/** Declaration of the notification queue header.
 * layout as specified in the data structure specification.
 */
typedef struct {
    uint32_t writeCnt;  /**< Write counter. */
    uint32_t readCnt;   /**< Read counter. */
    uint32_t queueSize; /**< Queue size. */
} notificationQueueHeader_t;

/** Queue struct which defines a queue object.
 * The queue struct is accessed by the queue<operation> type of
 * function. elementCnt must be a power of two and the power needs
 * to be smaller than power of uint32_t (obviously 32).
 */
typedef struct {
    notificationQueueHeader_t hdr;              /**< Queue header. */
    notification_t notification[MIN_NQ_ELEM];   /**< Notification elements. */
} notificationQueue_t;

#endif /** NQ_H_ */

/** @} */
