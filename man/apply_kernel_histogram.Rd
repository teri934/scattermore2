% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/apply_kernel_histogram.R
\name{apply_kernel_histogram}
\alias{apply_kernel_histogram}
\title{apply_kernel_histogram}
\usage{
apply_kernel_histogram(
  fhistogram,
  filter = "square",
  kernel_pixels = 2,
  sigma = 10
)
}
\arguments{
\item{fhistogram}{Matrix or array R datatype interpreted as histogram.}

\item{filter}{Either \code{square}(matrix of ones) or \code{gaussian} (symmetric).}

\item{kernel_pixels}{Used for determining size of kernel,
(\code{size = 2*kernel_pixels + 1}), defaults to \code{2}.}

\item{sigma}{Parameter for gaussian filtering, defaults to \code{10}.}
}
\value{
Float blurred histogram with the result.
}
\description{
Blur given histogram using \code{square} or \code{gauss} filtering.
}
