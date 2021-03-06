#' rgbwt_to_rgba_float
#'
#' Convert rgbwt matrix to float RGBA matrix.
#'
#' @param fRGBWT Float rgbwt matrix (`red`, `green`, `blue` channels, `weight` ~ sum of alphas,
#'                                   `transparency` ~ 1 - alpha, dimension nxmx5).
#' @return Float RGBA matrix.
#'
#' @export
#' @useDynLib scattermore2, .registration=TRUE
rgbwt_to_rgba_float <- function(fRGBWT)
{
    dim_RGBWT <- 5
    if(!is.array(fRGBWT) || dim(fRGBWT)[3] != dim_RGBWT) stop('not supported fRGBWT format')
    
    rows <- dim(fRGBWT)[1]
    cols <- dim(fRGBWT)[2]
    dim_RGBA <- 4
    
    W <- fRGBWT[,,4]
    R <- ifelse(W == 0, 0, fRGBWT[,,1] / W)  #preventing zero division
    G <- ifelse(W == 0, 0, fRGBWT[,,2] / W)
    B <- ifelse(W == 0, 0, fRGBWT[,,3] / W)
    A <- 1 - fRGBWT[,,5]
    
    RGBA <- rep(0, rows * cols * dim_RGBA)  #initialize matrix
    RGBA <- array(RGBA, c(rows, cols, dim_RGBA))
    RGBA[,,1] <- R * A                        #store premultiplied alpha
    RGBA[,,2] <- G * A
    RGBA[,,3] <- B * A
    RGBA[,,4] <- A
    
    fRGBA <- array(as.single(RGBA), c(rows, cols, dim_RGBA))
    return(fRGBA)
}
