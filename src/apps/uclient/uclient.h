/*
 * Copyright (C) 2011, 2012, 2013 Citrix Systems
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __UCLIENT_ECHO__
#define __UCLIENT_ECHO__

#include "ns_turn_utils.h"
#include "stun_buffer.h"
#include "session.h"

#include <openssl/ssl.h>
#include <openssl/dh.h>
#include <openssl/bn.h>

#ifdef __cplusplus
    "C" {
#endif

//////////////////////////////////////////////

#define STOPPING_TIME (10)
#define STARTING_TCP_RELAY_TIME (30)

typedef struct s_mclient {

    int clmessage_length;
    int do_not_use_channel;
    int clnet_verbose;
    int use_tcp;
    int use_sctp;
    int use_secure;
    char cert_file[1025];
    char pkey_file[1025];
    int hang_on;
    int c2c;
    ioa_addr peer_addr;
    int no_rtcp;
    int default_address_family;
    int dont_fragment;
    u08bits g_uname[STUN_MAX_USERNAME_SIZE+1];
    password_t g_upwd;
    char g_auth_secret[1025];
    int g_use_auth_secret_with_timestamp;
    int use_fingerprints;
    SSL_CTX *root_tls_ctx[32];
    int root_tls_ctx_num;
    int RTP_PACKET_INTERVAL;
    u08bits relay_transport;
    unsigned char client_ifname[1025];
    struct event_base* client_event_base;
    int passive_tcp;
    int mandatory_channel_padding;
    int negative_test;
    int negative_protocol_test;
    int dos;
    int random_disconnect;
    SHATYPE shatype;
    int mobility;
    int no_permissions;
    int extra_requests;
    band_limit_t bps;
    int dual_allocation;

    char origin[STUN_MAX_ORIGIN_SIZE+1];

    int oauth;
    oauth_key okey_array[3];

}   mclient;

#define UCLIENT_SESSION_LIFETIME (777)
#define OAUTH_SESSION_LIFETIME (555)

#define is_TCP_relay() (relay_transport == STUN_ATTRIBUTE_TRANSPORT_TCP_VALUE)
void mclient_init(mclient *this);
        
int start_mclient(s_mclient *this, const char *remote_address, int port,
		   const unsigned char* ifname, const char *local_address,
		   int messagenumber, int mclient);

int send_buffer(app_ur_conn_info *clnet_info, stun_buffer* message, int data_connection, app_tcp_conn_info *atc);
int recv_buffer(app_ur_conn_info *clnet_info, stun_buffer* message, int sync, int data_connection, app_tcp_conn_info *atc, stun_buffer* request_message);

void client_input_handler(evutil_socket_t fd, short what, void* arg);

turn_credential_type get_turn_credentials_type(void);

int add_integrity(app_ur_conn_info *clnet_info, stun_buffer *message);
int check_integrity(app_ur_conn_info *clnet_info, stun_buffer *message);

SOCKET_TYPE get_socket_type(void);

////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif //__UCLIENT_ECHO__

