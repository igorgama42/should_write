/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:00:51 by igama             #+#    #+#             */
/*   Updated: 2023/12/20 19:34:54 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Tips:
Storage Virtualization - Pooling of physical storage from multiple storage.
Virtualization - Creation of a virtual -- rather than actual -- version of something.
Device Driver - Special kind of software program that controls a specific hardware.

LVM - Logical Volume Management

Logical volume management (LVM) is a form of storage virtualization that offers 
system administrators a more flexible approach to managing disk storage space 
than traditional partitioning.
This type of virtualization tool is located within the device-driver stack on the operating system
LVM is a method of disk space management in the Linux OS. By creating a layer of
abstraction over physical storage, LVM also allows system administrators (sys admins)
to manage storage volumes across multiple physical hard disks.

With LVM, sys admins can increase disk input/output (I/O) by adding disk space to what
is known as a "logical storage volume" (or simply "logical volume"). These logical volumes
provide more flexibility for disk space creation, administration and management compared to
traditional storage management methods that directly use physical storage and increase the
maximum capacity of individual hard disk drives.

EXAMPLE:

TIPS:
PV - Physical Volume
LV - Logical Volume
VG - Volume Groups
PE - Physical Extents
LE - Logical Extents

Suppose there are three disks of 1 terabyte (TB) capacity each. EACH of these physical disks
is a physical volume (PV), designated PV 1, PV 2, and PV 3.
The total or aggregate available physical storage is 3 TB.
All three disks are added to Volume Group 1. Two logical volumes (LVs) are created from the
volume group: LV1 and LV2. Each LV has a capacity of 1.5 TB. Other LV combinations with
different capacities can also be created, such as the following:

* 3 LVs of capacities 1 TB, 500 Gigabytes (GB), 1,5 TB.
* 4 LVs of capacities 500 GB, 500 GB, 1 TB, 1 TB.
* 5 LVs of capacities 500 GB, 500 GB, 500 GB, 500 GB, 1 TB.

In this way, LVM adds flexibility to storage needs without increasing the complexity 
of storage management.
An appropriate LVM tool makes it easy to allocate hard drives to physical volumes, create
logical volumes from the physical volumes, and ultilametly, increase the size of a 
hard drive partition.

HOW DOES LOGICAL VOLUME MANAGEMENT WORK?

LVM works by breaking the PVs into physical extents (PEs). The PEs -- contiguous areas
of storage reserved for files -- are mapped onto logical extents (LEs) which are then
pooled into volume groups (VGs). These groups are linked together into LVs that act as
virtual disk partitions, which can be managed by using LVM and appropriate LVM tool.

Extents are present in both PVs and LVs. In either case, they are small, fixed-size units
of space. In particular, an extent is the smallest amount of space that can be allocated
by LVM in Linux. All LVs in a VG are of the same size. LVM maintains a mapping between all
logical and physical extents. This mapping is merely the LV, which can be expanded by adding
more extents or shrunk by removing extents.

*/
