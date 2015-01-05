/*
* Copyright (c) 2014 Microsoft Open Technologies, Inc. 
*   
*    Licensed under the Apache License, Version 2.0 (the "License"); you may 
*    not use this file except in compliance with the License. You may obtain 
*    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*    THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR 
*    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
*    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
*
*    See the Apache Version 2.0 License for specific language governing 
*    permissions and limitations under the License. 
*
*    Microsoft would like to thank the following companies for their review and
*    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
*    Dell Products, L.P., Facebook, Inc
*   
* Module Name:
*
*    saiport.h
*
* Abstract:
*
*    This module defines SAI Port API
*
*/

#if !defined (__SAIPORT_H_)
#define __SAIPORT_H_

#include <saitypes.h>

/*
*  Attribute data for SAI_PORT_ATTR_TYPE
*/
typedef enum _sai_port_type_t
{
    /* Actual port. N.B. Different from the physical port. */
    SAI_PORT_TYPE_LOGICAL,

    /* CPU Port */
    SAI_PORT_TYPE_CPU,

    /* Link-Aggregation Port */
    SAI_PORT_TYPE_LAG,

} sai_port_type_t;

/*
*  Attribute data for SAI_PORT_ATTR_OPER_STATUS 
*/
typedef enum _sai_port_oper_status_t
{
    /* Unknown */
    SAI_PORT_OPER_STATUS_UNKNOWN,

    /* Up */
    SAI_PORT_OPER_STATUS_UP,

    /* Down */
    SAI_PORT_OPER_STATUS_DOWN,

    /* Test Running */
    SAI_PORT_OPER_STATUS_TESTING,

    /* Not Present */
    SAI_PORT_OPER_STATUS_NOT_PRESENT

} sai_port_oper_status_t;

/*
*  Attribute data for SAI_PORT_STP_STATE
*/
typedef enum _sai_port_stp_state_t 
{
    /* Port is Disabled  */
    SAI_PORT_STP_STATE_DISABLED,

    /* Port is Listening */
    SAI_PORT_STP_STATE_LISTENING,

    /* Port is Learning */
    SAI_PORT_STP_STATE_LEARNING,

    /* Port is Forwarding */
    SAI_PORT_STP_STATE_FORWARDING,

    /* Port is Blocking */
    SAI_PORT_STP_STATE_BLOCKING,

    /* Port is Discarding */
    SAI_PORT_STP_STATE_DISCARDING,

} sai_port_stp_state_t;

/*
* Attribute data for SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL
*/
typedef enum _sai_port_flow_control_mode_t
{
    /* disable flow control for both tx and rx */
    SAI_PORT_FLOW_CONTROL_DISABLE,

    /* enable flow control for tx only */
    SAI_PORT_FLOW_CONTROL_TX_ONLY,

    /* enable flow control for rx only */
    SAI_PORT_FLOW_CONTROL_RX_ONLY,

    /* enable flow control for both tx and rx */
    SAI_PORT_FLOW_CONTROL_BOTH_ENABLE,

} sai_port_flow_control_mode_t;

/*
* Attribute data for SAI_PORT_ATTR_INTERNAL_LOOPBACK
*/
typedef enum _sai_port_internal_loopback_mode_t
{
    /* disable internal loopback */
    SAI_PORT_INTERNAL_LOOPBACK_NONE,

    /* port internal loopback at phy module */
    SAI_PORT_INTERNAL_LOOPBACK_PHY,

    /* port internal loopback at mac module */
    SAI_PORT_INTERNAL_LOOPBACK_MAC

} sai_port_internal_loopback_mode;

/*
* Attribute data for SAI_PORT_ATTR_FDB_LEARNING
*/
typedef enum _sai_port_fdb_learning_mode_t 
{
    /* Learning diaable. Do not learn new mac address */
    SAI_PORT_LEARN_MODE_DISABLE,

    /* Hardware learning */
    SAI_PORT_LEARN_MODE_HW,

} sai_port_fdb_learning_mode_t;

/*
*  Attribute Id in sai_set_port_attribute() and 
*  sai_get_port_attribute() calls
*/
typedef enum _sai_port_attr_t
{
    /* READ-ONLY */

    /* Admin Mode [sai_port_type_t] */
    SAI_PORT_ATTR_TYPE,

    /* Operational Status [sai_port_oper_status_t] */
    SAI_PORT_ATTR_OPER_STATUS,


    /* READ-WRITE */
    /* Speed in Mbps [uint_t] */
    SAI_PORT_ATTR_SPEED,

    /* Admin Mode [bool] */
    SAI_PORT_ATTR_ADMIN_STATE,

    /* Default VLAN [uint32_t] 
    *   Untagged ingress frames are tagged with default VLAN 
    */
    SAI_PORT_ATTR_DEFAULT_VLAN,

    /* Default VLAN Priority [int] */
    SAI_PORT_ATTR_DEFAULT_VLAN_PRIORITY,

    /* Ingress Filtering (Drop Frames with Unknown VLANs) [bool] */
    SAI_PORT_ATTR_INGRESS_FILTERING,

    /* Dropping of untagged frames on ingress [bool] */
    SAI_PORT_ATTR_DROP_UNTAGGED, 

    /* Dropping of tagged frames on ingress [bool] */
    SAI_PORT_ATTR_DROP_TAGGED, 

    /* Internal loopback control [sai_port_loopback_mode_t] */
    SAI_PORT_ATTR_INTERNAL_LOOPBACK,

    /* FDB Learning mode [sai_port_fdb_learning_mode_t] */
    SAI_PORT_ATTR_FDB_LEARNING,

    /* Stp mode [sai_port_stp_state_t] */
    SAI_PORT_ATTR_STP_STATE,

    /* Update DSCP of outgoing packets [bool] */
    SAI_PORT_ATTR_UPDATE_DSCP,

    /* MTU [uint32_t] */
    SAI_PORT_ATTR_MTU,

    /* Sflow control */
    SAI_PORT_ATTR_SFLOW,

    /* [bool] */
    SAI_PORT_ATTR_FLOOD_STORM_CONTROL,

    /* [bool] */
    SAI_PORT_ATTR_BROADCAST_STORM_CONTROL,

    /* [bool] */
    SAI_PORT_ATTR_MULTICAST_STORM_CONTROL,

    /* [sai_port_flow_control_mode_t] */
    SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL,

    /* Maximum number of learned MAC addresses [uint32_t] */
    SAI_PORT_ATTR_MAX_LEARNED_ADDRESSES,

    /* Action for packets with unknown source mac address
     * when FDB learning limit is reached.
     * [sai_packet_action_t] */
    SAI_PORT_ATTR_FDB_LEARNING_LIMIT_VIOLATION,

    /* -- */

    /* Custom range base value */
    SAI_PORT_ATTR_CUSTOM_RANGE_BASE  = 0x10000000

} sai_port_attr_t;

/*
*  Port counter IDs in sai_get_port_stat_counters() call
*/
typedef enum _sai_port_stat_counter_t
{
    SAI_PORT_STAT_IF_IN_OCTETS,
    SAI_PORT_STAT_IF_IN_UCAST_PKTS,
    SAI_PORT_STAT_IF_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IF_IN_DISCARDS,
    SAI_PORT_STAT_IF_IN_ERRORS,
    SAI_PORT_STAT_IF_IN_UNKNOWN_PROTOS,
    SAI_PORT_STAT_IF_IN_BROADCAST_PKTS,
    SAI_PORT_STAT_IF_IN_MULTICAST_PKTS,
    SAI_PORT_STAT_IF_IN_VLAN_DISCARDS,
    SAI_PORT_STAT_IF_OUT_OCTETS,
    SAI_PORT_STAT_IF_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_DISCARDS,
    SAI_PORT_STAT_IF_OUT_ERRORS,
    SAI_PORT_STAT_IF_OUT_QLEN,
    SAI_PORT_STAT_IF_OUT_BROADCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_MULTICAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_DROP_EVENTS,
    SAI_PORT_STAT_ETHER_STATS_MULTICAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_BROADCAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_UNDERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_STATS_FRAGMENTS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_64O_CTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_65_TO_127_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_128_TO_255_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_256_TO_511_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_512_TO_1023_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_1024_TO_1518_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_RX_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_TX_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_STATS_JABBERS,
    SAI_PORT_STAT_ETHER_STATS_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS,
    SAI_PORT_STAT_ETHER_STATS_COLLISIONS,
    SAI_PORT_STAT_ETHER_STATS_CRC_ALIGN_ERRORS,
    SAI_PORT_STAT_ETHER_STATS_TX_NO_ERRORS,
    SAI_PORT_STAT_ETHER_STATS_RX_NO_ERRORS,
    SAI_PORT_STAT_IP_IN_RECEIVES,
    SAI_PORT_STAT_IP_IN_OCTETS,
    SAI_PORT_STAT_IP_IN_UCAST_PKTS,
    SAI_PORT_STAT_IP_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IP_IN_DISCARDS,
    SAI_PORT_STAT_IP_OUT_OCTETS,
    SAI_PORT_STAT_IP_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IP_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IP_OUT_DISCARDS,
    SAI_PORT_STAT_IPV6_IN_RECEIVES,
    SAI_PORT_STAT_IPV6_IN_OCTETS,
    SAI_PORT_STAT_IPV6_IN_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_MCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_DISCARDS,
    SAI_PORT_STAT_IPV6_OUT_OCTETS,
    SAI_PORT_STAT_IPV6_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_MCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_DISCARDS
} sai_port_stat_counter_t;


/*
* Routine Description:
*   Set port attribute value.
*
* Arguments:
*    [in] port_id - port id
*    [in] attr - attribute
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_set_port_attribute_fn)(
    _In_ sai_port_id_t port_id, 
    _In_ const sai_attribute_t *attr
    );


/*
* Routine Description:
*   Get port attribute value.
*
* Arguments:
*    [in] port_id - port id
*    [in] attr_count - number of attributes
*    [inout] attr_list - array of attributes
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_get_port_attribute_fn)(
    _In_ sai_port_id_t port_id,
    _In_ int attr_count,
    _Inout_ sai_attribute_t *attr_list
    );

/*
* Routine Description:
*   Get port statistics counters.
*
* Arguments:
*    [in] port_id - port id
*    [in] counter_ids - specifies the array of counter ids
*    [in] number_of_counters - number of counters in the array
*    [out] counters - array of resulting counter values.
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/ 
typedef sai_status_t (*sai_get_port_stats_fn)(
    _In_ sai_port_id_t port_id,
    _In_ const sai_port_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
    );

/*
* Routine Description:
*   Port state change notification
*   Passed as a parameter into sai_initialize_switch()
*
* Arguments:
*   [in] port_id - port id
*   [in] port_state - new port state
*
* Return Values:
*    None
*/
typedef void (*sai_port_state_change_notification_fn)(
    _In_ sai_port_id_t port_id,
    _In_ sai_port_oper_status_t port_state
    );

/*
* Port methods table retrieved with sai_api_query()
*/
typedef struct _sai_port_api_t
{
    sai_set_port_attribute_fn       set_port_attribute;
    sai_get_port_attribute_fn       get_port_attribute;
    sai_get_port_stats_fn           get_port_stats;

} sai_port_api_t;

#endif // __SAIPORT_H_

