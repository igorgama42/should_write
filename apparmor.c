/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apparmor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 08:31:51 by igama             #+#    #+#             */
/*   Updated: 2023/12/22 11:28:31 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

AppArmor is an important security feature that's been included by default with Ubuntu
since Ubunut 7.10. However, it runs silently in the background, so you may not be
aware of what it is and what it's doing.

WHAT IS APPARMOR?

AppArmor is similar to SELinux, used by default in Fedora and Red Hat. While they work
differently, both AppArmor and SELinux provide "mandatory access control"(MAC) security.
In effect, AppArmor allows Ubuntu's developers to restrict the actinos processes can take.

For example, one application that's restricted in Ubuntu's default configuration is the
Evince PDF viewer. While Evince may run as your user account, it can only take specific
actions. Evince only has the bare minimum of permissions needed to run and work with PDF
documents. If a vulnerability were discovered in Evince's PDF renderer and you opened a
malicious PDF document that took over Evince, AppArmor would restrict the damage Evince 
could do. In the traditional Linux security model, Evince would have access to everything
you have access to. With AppArmor, it only has access to things that a PDF viewer needs
access to.

AppArmor is particularly useful for restricting software that may be exploited, such as a
web browser or server software.

VIEWING APPARMOR'S STATUS

To view AppArmor's status, run the following command in a terminal:

sudo apparmor_status

You'll see wheter AppArmor is running on your sistem (It's running by default), the AppArmor profiles that are installed, and the confined processes that are running.

APPARMOR PROFILES













*/
