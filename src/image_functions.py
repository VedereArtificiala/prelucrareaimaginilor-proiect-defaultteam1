
#   Facultatea de Automatică și Calculatoare
#   Proiectarea Algoritmilor - Microscopie digitală - segmentare celule grăsime pentru analiza steatozei hepatice 
#   Darie Alexandru     - 1309B
#   Ifrim Tudor-Nicolae - 1309A
#
# ------------------------------------------------------------------------------
# Importing modules
# ------------------------------------------------------------------------------
import numpy as np
import os
import sys

#Checking if OpenCV is installed, if not, install it
try:
    import cv2
except ImportError:
    import pip
    pip.main(['install', 'opencv-python'])
    import cv2


# ------------------------------------------------------------------------------
# Constants
# ------------------------------------------------------------------------------

# Path to the folder containing the images 
PATH_TO_IMAGES = os.path.join(os.path.dirname(__file__), "images")


# ------------------------------------------------------------------------------
# Functions
# ------------------------------------------------------------------------------

def filter_color(path_to_file, hex_color):
    
    img = cv2.imread(path_to_file)                           # Load the image

    bgr_color = np.array([int(hex_color[i:i+2], 16)          # Convert hex color to BGR format
                          for i in (0, 2, 4)][::-1])         # (that's what OpenCV uses)

    # =====================================INFO=====================================
    # [MASKING]
    # The mask is an image with the same size as the original image, with pixels set to WHITE
    # if the corresponding pixel in the original image is within the specified color range,
    # and BLACK otherwise.
    #
    # [BITWISE AND]
    # The bitwise_and function takes two images of the same size and a mask, and returns
    # an image where each pixel is the bitwise AND of the corresponding pixels in the
    # first two images, but only if the corresponding pixel in the mask is WHITE.)
    # ==============================================================================

    mask = cv2.inRange(img, bgr_color, bgr_color)            # Create a mask for the specified color
    filtered_img = cv2.bitwise_and(img, img, mask=mask)      # Apply the mask to the image


    name, ext = os.path.splitext(path_to_file)               # Split the file path into its components
    new_name = f"{name}_filtered_{hex_color}{ext}"           # Create the new image and save it

    cv2.imwrite(new_name, filtered_img)

filter_color(os.path.join(PATH_TO_IMAGES, "photo.png"), "00a4eb")