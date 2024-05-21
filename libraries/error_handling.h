/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:04:12 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/20 14:27:15 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

//
// Map error
//

# define ERROR_0 "Invalid map, file"
# define ERROR_1 "Invalid map, the map provided is not a square."
# define ERROR_2 "Invalid map, above or below it is not surrounded by walls."
# define ERROR_3 "I. M. ,on the right or left it is not surrounded by walls"
# define ERROR_4 "Invalid map, the number of elements is incorrect."
# define ERROR_5 "Invalid map, extension (.ber) is the only one allowed."
# define ERROR_6 "I. M., The player cannot reach all collectibles or the exit"
# define ERROR_7 "I. M., Map with incompatible characters"

#endif
