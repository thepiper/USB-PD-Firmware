/*
 * PD Buddy - USB Power Delivery for everyone
 * Copyright (C) 2017 Clayton G. Hobbs <clay@lakeserv.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PDB_DEVICE_POLICY_MANAGER_H
#define PDB_DEVICE_POLICY_MANAGER_H

#include <stdbool.h>

#include "messages.h"


/* Whether the DPM is able to turn on the output */
extern bool pdb_dpm_output_enabled;

/* Whether the DPM sets the LED to indicate the PD status */
extern bool pdb_dpm_led_pd_status;

/* Whether the device is capable of USB communications */
extern bool pdb_dpm_usb_comms;

/* The most recently received Source_Capabilities message */
extern const union pd_msg *pdb_dpm_capabilities;


/*
 * Create a Request message based on the given Source_Capabilities message.
 *
 * Returns true if sufficient power is available, false otherwise.
 */
bool pdb_dpm_evaluate_capability(const union pd_msg *capabilities, union pd_msg *request);

/*
 * Create a Sink_Capabilities message for our current capabilities.
 */
void pdb_dpm_get_sink_capability(union pd_msg *cap);

/*
 * Return whether or not GiveBack support is enabled.
 */
bool pdb_dpm_giveback_enabled(void);

/*
 * Evaluate whether or not the currently offered Type-C Current can fulfill our
 * power needs.
 *
 * Returns true if sufficient power is available, false otherwise.
 */
bool pdb_dpm_evaluate_typec_current(void);

/*
 * Indicate that power negotiations are starting.
 */
void pdb_dpm_pd_start(void);

/*
 * Transition to Sink Standby if necessary.
 */
void pdb_dpm_sink_standby(void);

/*
 * Set the output state, with LED indication.
 */
void pdb_dpm_output_set(bool state);

/*
 * Transition the sink to default power.
 */
void pdb_dpm_output_default(void);


#endif /* PDB_DEVICE_POLICY_MANAGER_H */
